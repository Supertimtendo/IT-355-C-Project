/**
 * @file main.c
 * @author Tim Buranicz, Tom Freier
 * @version 1.0
 * Main file to run
 */
#include "account.h"
#include "bank.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
    bank isuBank;
    isuBank.maxAccounts = MAX_NUM_ACCOUNTS;
    isuBank.curAccountCount = 0;



    /**
     * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
     * 
     * C is a memory-unsafe language so the mismanagement of memory is common and can lead to freeing memory multiple times leading to undefined behavior.
     * 
     * To combat whenever you declare memory in C you should have no expectation that someone else will free it.
     * This is generally implemented by declaring and freeing memory within the same function (or same layer of abstraction).
     */
    initializeAccounts(isuBank);
    // To stuff with the bank, get user input etc.
    bool continueRunning = true;
    char userInput;
    while(continueRunning){
        printf("Select from menu below:\n1. Create an Account.\n2. Update an Account.\n3. Withdraw\n4. Deposit.\n5. Transaction with Another Account.\n6. Exit");
        //TODO: I/O rule guy check this for better option
        sscanf("%c", &userInput);

        //TODO: Potentially make this a switch case??

        if(userInput=='1'){
            addAccount(isuBank);
        }
        else if(userInput=='2'){
            updateAccount(isuBank);
        }
        else if(userInput=='3'){
            withdrawal(isuBank);
        }
        else if(userInput=='4'){
            deposit(isuBank);
        }
        else if(userInput=='5'){
            transferFunds(isuBank);
        }
        else if(userInput=='6'){
            continueRunning = false;
            printf("Exiting program.\n");
        }
        else{
            printf("Invalid input because select a number from the entry.");
        }
    }

    // In the same layer of abstraction (the main method), thus successfully implementing the rule.
    freeAccounts(isuBank);
    return 0;
}