/**
 * @file main.c
 * @author Tim Buranicz and Tom Freier
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
     * C is a memory-unsafe language so the mismangment of memory is common and can lead to freeing memory multiple times leading to undefined behavior.
     * 
     * To combat whenever you declare memory in C you should have no expectation that someone else will free it.
     * This is generally implemented by declaring and freeing memory within the same function (or same layer of abstraction).
     */
    intializeAccounts(isuBank);
    // To stuff with the bank, get user input etc.
    bool continueRunning = true;
    char userInput[100]; 
    while(continueRunning){
        printf("Select from menu below:\n1. Create an Account.\n2. Update an Account.\n3. Withdraw\n4. Deposit.\n5. Transaction with Another Account.\n6. Exit");
        scanf("%100s", userInput);
        if(strncmp(userInput,"1",1) == 0){
            addAccount(isuBank);
        }
        else if(strncmp(userInput, "2",1) == 0){
            updateAccount(isuBank);
        }
        else if(strncmp(userInput,"3", 1) ==0){
            withdrawl(isuBank);
        }
        else if(strncmp(userInput, "4", 1) == 0){
            deposit(isuBank);
        }
        else if(strncmp(userInput,"5",1) == 0){
            transferFunds(isuBank);
        }
        else if(strncmp(userInput, "6",1 == 0)){
            continueRunning = false;
            printf("Exitting program.\n");
        }
        else{
            printf("Invalid input because select a number from the entry.");
        }
    }

    // In the same layer of abstraction (the main method), thus succesfully implementing the rule.
    freeAccounts(isuBank);
    return 0;
}