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
#include <unistd.h>
/**
 * @brief Exit handler that prints the contents of the program upon exiting
 * 
 * Implementation of Rule: ENV32-C. All exit handlers must return normally.
 * This is correctly implemented at the exit handler doesn't call the exit function and ends with a return call.
 * 
 */
void printProgram(){
    /**
     * @brief Example of rule: ENV33-C. Do not call system()
     * 
     * System() is a powerful function that allows for any command to be ran. Instead function in the exec family should be used to prevent attackers from entering malicious commands.
     * 
     * This is a succesfuly implementation because it uses the execv function instead of system.
     */
    char programName[] = "main.c";
    char* args[3] = {"/bin/cat",programName,NULL};
    pid_t pid = fork(); // creating a child process to run the execv command
    if(pid == -1){ // Error
        fprintf(stderr,"Error creating child process on pid() call.\n");
    }
    else if(pid == 0){ // Child process
        /* Child process calling command to execute*/
        printf("Printing contents of program: %s.\n", programName);
        execv(args[0], args);
    }
    else{ // Parent process
        // Implementation of ENV32-C, this exit handler function returns normally. 
        return;
    } 
}
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
    bank isuBank;
    isuBank.maxAccounts = MAX_NUM_ACCOUNTS;
    isuBank.curAccountCount = 0;

    //TEST CASE for updating info of struct
    account a = createAccount();
    changeUsername(&a);
    changePassword(&a);
    changeName(&a);
    printAccount(&a);

    /**
     * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
     * 
     * C is a memory-unsafe language so the mismanagement of memory is common and can lead to freeing memory multiple times leading to undefined behavior.
     * 
     * To combat whenever you declare memory in C you should have no expectation that someone else will free it.
     * This is generally implemented by declaring and freeing memory within the same function (or same layer of abstraction).
     */
    initializeAccounts(&isuBank);
    // Do stuff with the bank, get user input etc.
    bool continueRunning = true;
    char userInput;
    while(continueRunning){
        printf("Select from menu below:\n1. Create an Account.\n2. Update an Account.\n3. Withdraw\n4. Deposit.\n5. Transaction with Another Account.\n6. Exit");
        //TODO: I/O rule guy check this for better option
        scanf("%c", &userInput);

        //TODO: Potentially make this a switch case??

        if(userInput=='1'){
            addAccount(&isuBank);
        }
        else if(userInput=='2'){
            updateAccount(&isuBank);
        }
        else if(userInput=='3'){
            withdrawal(&isuBank);
        }
        else if(userInput=='4'){
            deposit(&isuBank);
        }
        else if(userInput=='5'){
            transferFunds(&isuBank);
        }
        else if(userInput=='6'){
            continueRunning = false;
            printf("Exiting program.\n");
        }
        else{
            printf("Invalid input because select a number from the entry.");
        }
    }

    // In the same layer of abstraction (the main method), thus successfully implementing the rule MEM00-C
    freeAccounts(&isuBank);

    if(atexit(printProgram) != 0){
        fprintf(stderr,"Error from exit handler: printProgram\n");
    }
    return 0;
}