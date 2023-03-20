/**
 * @file main.c
 * @author Tim Buranicz, Tom Freier, Lucas Beebe
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
#include <sys/stat.h>

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
    /**
     * @brief Example of recommendation: ARR02-C. Explicitly specify array bounds, even if implicitly defined by an initializer
     * 
     * The character array programName is initialized with the string "main.c", but the size 
     * of the array is still specified as 6 because it helps the compiler send warnings and prevent/detect errors
    */
    char programName[6] = "main.c";
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
    //structs for file tracking -- part of FIO01 and FIO05
    struct stat original;
    struct stat new;

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
    fprintf(stdout, "Would you like to retrieve previous bank account information? (yes/no): ");
    while(strcmp(userChoice, "yes") != 0 && strcmp(userChoice, "Yes") != 0 && strcmp(userChoice, "no") != 10 && strcmp(userChoice, "No") != 10){
        if(fgets(userChoice, sizeof(userChoice), stdin)){
            
        }else{
            fprintf(stderr, "Error: fgets() failure during user input retrieval");
            exit(1);
        }
    }
    /**
     * @brief Example of recommendation: EXP34-C. Do not dereference null pointers
     * The while loop checks each time and make sure that a null value is not pulled form the file.
     */
    if(strcmp(userChoice, "yes") == 0 || strcmp(userChoice, "Yes") == 0){

        printf("\nRetrieving data from file...\n");
        FILE *fp;
        fp = fopen("bankdata.txt", "r");
        int fd = fileno(fp);
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
            /**
             * @brief Example of rule FIO37-C. Do not assume that fgets() or fgetws() returns a nonempty string when successful
             * 
             * In the if statement fgets() is run and it is checked whether or not it failed, but
             * there is another check to make sure that even if fgets() succeeds that the string is not empty.
             * If the string is empty, an error message is still shown.
             * 
             */
            if(fgets(userName, sizeof(userName),fp)){
                if(strlen(userName) == 0){
                    fprintf(stderr, "fgets() succeeded, but it is an empty string");
                }
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
                exit(1);
            }
            
            if(fgets(password, sizeof(password), fp)){
                if(strlen(password) == 0){
                    fprintf(stderr, "fgets() succeeded, but it is an empty string");
                }
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            
            if(fgets(firstName, sizeof(firstName), fp)){
                if(strlen(firstName) == 0){
                    fprintf(stderr, "fgets() succeeded, but it is an empty string");
                }
            }else{
                fprintf(stderr,"There was an error reading file with fgets()");
            }
            
            if(fgets(lastName, sizeof(lastName), fp)){
                if(strlen(lastName) == 0){
                    fprintf(stderr, "fgets() succeeded, but it is an empty string");
                }
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            
            if(fgets(accountId, sizeof(accountId), fp)){
                if(strlen(accountId) == 0){
                    fprintf(stderr, "fgets() succeeded, but it is an empty string");
                }
                accountIdVal = atoi(accountId);
            }else{
                fprintf(stderr, "There was an error reading file with fgets()");
            }
            
            if(fgets(balance, sizeof(balance), fp)){
                if(strlen(balance) == 0){
                    fprintf(stderr, "fgets() succeeded, but it is an empty string");
                }
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
            account accnt;
            allocateStrings(&accnt);
            sprintf(accnt.firstName, "%s", firstName);
            sprintf(accnt.lastName, "%s", lastName);
            sprintf(accnt.username, "%s", userName);
            sprintf(accnt.password, "%s", password);
            accnt.accountID = accountIdVal;
            accnt.balance = balanceFloat;
            isuBank.accounts[isuBank.curAccountCount] = accnt;
            isuBank.curAccountCount++;
        }
        if(fstat(fd, &original) < 0){
            fprintf(stderr, "fstat() failed");
        }
        fclose(fp);

    }else{
        printf("\nNot retrieving data from file\n");
    }
     /**
     * @brief Example of recommendation: API01-C. Avoid laying out strings in memory directly before sensitive data
     * We get the informtion form the file before we get any type of info from the user making sure that the user input cannot overwrite the data if a buffer overflow happens
     */
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

    FILE *fp;
    /**
     * @brief Example of rule FIO39-C. Do not alternately input and output form a stream without an intervening flush or positioning call.
     * 
     * By reopening the file, the input and output from the stream is not immediately alternated. The risk of undefined results is 
     * eliminated because a new file stream is created. It is effectively automatically repositioning at the top
     * of the file.
     */
    fp = fopen("bankdata.txt","w");
    int fd = fileno(fp);

    /**
     * @brief Example of recommendations FIO01-C and FIO05. FIO01-C is "Be careful using 
     * functions that use file names for identification". FIO05-C is "Identify files using multiple file attributes".
     * 
     * Both of these recommendations are followed here because the file being written to is being verified as the
     * same file that was read from through it's file number and by using sys/stat.h. In order to identify the file using 
     * multiple attributes, the file number is used to identify it as well as the file name.
     */
    if(fstat(fd, &new) < 0){
        fprintf(stderr, "fstat() failed");
    }

    if((original.st_dev != new.st_dev) || (original.st_ino != new.st_ino)){
        fprintf(stderr, "Error: the file read from has been changed from the file about to be written to");
    }
    int accountCounter = isuBank.curAccountCount;

    while(accountCounter != 0){
        account acc = isuBank.accounts[accountCounter-1];
        char usernameBuffer[100];
        /**
             * @brief Example of rule FIO37-C. Do not assume that fgets() or fgetws() returns a nonempty string when successful
             * 
             * In the if statement fgets() is run and it is checked whether or not it failed, but
             * there is another check to make sure that even if fgets() succeeds that the string is not empty.
             * If the string is empty, an error message is still shown.
             * 
             */
        if(strchr(acc.username,'\n')){
            sprintf(usernameBuffer,"%s", acc.username);
        }else{
            sprintf(usernameBuffer,"%s\n", acc.username);
        }
        
        fwrite(usernameBuffer,1,strlen(usernameBuffer),fp);

        char passwordBuffer[100];

        if(strchr(acc.password, '\n')){
            sprintf(passwordBuffer,"%s", acc.password);
        }else{
            sprintf(passwordBuffer,"%s\n", acc.password);
        }
        
        fwrite(passwordBuffer,1,strlen(passwordBuffer),fp);

        char firstNameBuffer[100];

        if(strchr(acc.firstName, '\n')){
            sprintf(firstNameBuffer,"%s", acc.firstName);
        }else{
            sprintf(firstNameBuffer,"%s\n", acc.firstName);
        }
        
        fwrite(firstNameBuffer, 1, strlen(firstNameBuffer), fp);

        char lastNameBuffer[100];
        if(strchr(acc.lastName, '\n')){
            sprintf(lastNameBuffer,"%s", acc.lastName);
        }else{
            sprintf(lastNameBuffer,"%s\n", acc.lastName);
        }
        
        fwrite(lastNameBuffer, 1, strlen(lastNameBuffer), fp);
        char accountIDStr[100];
        sprintf(accountIDStr, "%d\n",acc.accountID);
        fwrite(accountIDStr,strlen(accountIDStr),1,fp);
        char balanceStr[100];
        if(accountCounter == 1){
            sprintf(balanceStr,"%f",acc.balance);
        }else{
            sprintf(balanceStr,"%f\n",acc.balance);
        }
        
        fwrite(balanceStr,strlen(balanceStr),1,fp);
        accountCounter--;
    }
    fclose(fp);

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
