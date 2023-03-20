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
#include <sys/types.h>
#include <sys/wait.h>

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
     * This is also an example of these array rules with the out of bounds and size exceptions
     * ARR30-C. Do not form or use out-of-bounds pointers or array subscripts
     * ARR32-C. Ensure size arguments for variable length arrays are in a valid range 
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
        wait(&pid); 
        printf("\nPrinted contents of program. Exiting now.\n");
        return;
    } 
}
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
    bank isuBank;

    /**
     * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
     * 
     * C is a memory-unsafe language so the mismanagement of memory is common and can lead to freeing memory multiple times leading to undefined behavior.
     * 
     * To combat whenever you declare memory in C you should have no expectation that someone else will free it.
     * This is generally implemented by declaring and freeing memory within the same function (or same layer of abstraction).
     */
    initializeAccounts(&isuBank);

    char userChoice[4] = "\0";
    bool retrieveFromFile = false;
    fprintf(stdout, "Would you like to retrieve previous bank account information? (yes/no): ");
    while(strcmp(userChoice, "yes") != 0 && strcmp(userChoice, "Yes") != 0 && strcmp(userChoice, "no") != 0 && strcmp(userChoice, "No") != 0){
        if(fgets(userChoice, sizeof(userChoice), stdin)){
            char *newLinePointer = strchr(userChoice, '\n');
            if(newLinePointer){
                *newLinePointer = '\0';
            }
        }else{
            fprintf(stderr, "Error: fgets() failure during user input retrieval");
            exit(1);
        }
    }
    if(strcmp(userChoice, "yes") == 0 || strcmp(userChoice, "Yes") == 0){
        printf("\nRetrieving data from file...\n");
        retrieveFromFile = true;
        FILE *fp;
        fp = fopen("bankdata.txt", "r");
        int accountCounter = 0;
        char accountId[100];
        int accountIdVal;
        char userName[100];
        char password[100];
        char firstName[100];
        char lastName[100];
        char balance[100];
        float balanceFloat;
        while(!feof(fp)){
            if(fgets(userName, sizeof(userName),fp)){
                
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
                exit(1);
            }
            
            if(fgets(password, sizeof(password), fp)){
                
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            
            if(fgets(firstName, sizeof(firstName), fp)){
                
            }else{
                fprintf(stderr,"There was an error reading file with fgets()");
            }
            
            if(fgets(lastName, sizeof(lastName), fp)){
                
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            
            if(fgets(accountId, sizeof(accountId), fp)){
                accountIdVal = atoi(accountId);
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            
            if(fgets(balance, sizeof(balance), fp)){
                balanceFloat = atof(balance);
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            accountCounter++;
            fprintf(stdout, "\nAccount %d:\n", accountIdVal);
            fprintf(stdout, "Username: %s\n", userName);
            fprintf(stdout, "Password: %s\n", password);
            fprintf(stdout, "First Name: %s\n", firstName);
            fprintf(stdout, "Last Name: %s\n", lastName);
            fprintf(stdout, "Balance: %f\n",balanceFloat);
        }

    }else{
        printf("\nNot retrieving data from file\n");
    }
    // Do stuff with the bank, get user input etc.
    bool continueRunning = true;
    int userInput;
    while(continueRunning){
        printf("Select from menu below:\n1. Create an Account.\n2. Update an Account.\n3. Withdraw\n4. Deposit.\n5. Transaction with Another Account.\n6. Exit\n");
        //TODO: I/O rule guy check this for better option
        scanf("%d", &userInput);

        switch(userInput){
         case 1: addAccount(&isuBank); break;
         case 2: updateAccount(&isuBank); break;
         case 3: withdrawal(&isuBank); break;
         case 4: deposit(&isuBank); break;
         case 5: transferFunds(&isuBank); break;
         case 6: continueRunning = false; printf("Exiting program.\n"); break;
         default: printf("Invalid input because select a number from the entry.\n"); break;
        }

    }

    int accountCounter = isuBank.curAccountCount;
    while(accountCounter != 0){
        account acc = isuBank.accounts[accountCounter-1];
        FILE *fp;
        fp = fopen("bankdata.txt","w");
        fwrite(acc.username,1,strlen(acc.username),fp);
        fwrite(acc.password,1,strlen(acc.password),fp);
        fwrite(acc.firstName, 1, strlen(acc.firstName), fp);
        fwrite(acc.lastName, 1, strlen(acc.lastName), fp);
        char accountIDStr[100];
        sprintf(accountIDStr, "%d",acc.accountID);
        fwrite(accountIDStr,strlen(accountIDStr),1,fp);
        char balanceStr[100];
        sprintf(balanceStr,"%f",acc.balance);
        fwrite(balanceStr,strlen(balanceStr),1,fp);
        accountCounter--;
    }


    // In the same layer of abstraction (the main method), thus successfully implementing the rule MEM00-C
    freeAccounts(&isuBank);

    if(atexit(printProgram) != 0){
        fprintf(stderr,"Error from exit handler: printProgram\n");
    }

    /**
     * @brief Example of recommendation: FIO23-C. Do not exit with unflushed data on stdout or stderr 
     * Checking if their is any kind of errror at the end of the stout stream and printing an error message if their is.
     */
    if(fflush(stdout) == EOF)
   {
     printf("error when closing stream");
   }
    return 0;
}
