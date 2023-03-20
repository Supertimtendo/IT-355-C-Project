/**
 * @file account.c
 * @author Tim Buranicz, Tom Freier, Lucas Beebe
 * @version 1.0
 * Implementation of account
 */
#include <stdio.h>
#include <string.h>
#include "account.h"
#include <float.h>
#include <limits.h>
#include <fenv.h>
#include <stdlib.h>
/**
 * Method to take in info that is then stored in an account struct
 * @return Returns created struct
 */
account createAccount(){
    account a;
    allocateStrings(&a);
    changeName(&a);
    changeUsername(&a);
    changePassword(&a);
    return a;
}

/**
 * Allocates the memory space for the four strings used in the struct
 * @param a account to allocate the strings for
*/
void allocateStrings(account *a){
    a->firstName = (char *) malloc(MAX_STRING_LENGTH*sizeof(char));
    a->lastName = (char *) malloc(MAX_STRING_LENGTH*sizeof(char));
    a->username = (char *) malloc(MAX_STRING_LENGTH*sizeof(char));
    a->password = (char *) malloc(MAX_STRING_LENGTH*sizeof(char));
}
/**
 * Frees the memory space for the four strings used in the struct
 * @param a account to free the memory of
*/
void freeStrings(account *a){
    if(a->firstName!=NULL){
        free(a->firstName);
        a->firstName=NULL;
    }
    if(a->lastName!=NULL){
        free(a->lastName);
        a->lastName=NULL;
    }
    if(a->username!=NULL){
        free(a->username);
        a->username=NULL;        
    }
    if(a->password!=NULL){
        free(a->password);
        a->password=NULL;        
    }
}
/**
 * Change an account's name
 * @param a Changes name of account
 */
void changeName(account *a){
    //TODO: Add error message if new string is too long
    //First name change:
    //STR31-C: The new char array is null-terminated since no size is given, so the compiler automatically allocates the correct amount of memory
    char* newFirstName = (char *) malloc(sizeof(char)*MAX_STRING_LENGTH);
    printf("Enter New First Name:\n");
    scanf("%s", newFirstName);
    size_t fstNameLength = strlen(newFirstName);
    //STR31-C: Checks for enough space prior to copying, including the null terminator
    if(fstNameLength < (MAX_STRING_LENGTH-1)) {
        //STR32-C: Since the above char array is properly null-terminated, we do not have to worry about any overflows here
        //STR38-C: Since all our char arrays are narrow, there is no chance of an error when using functions that expect narrow strings
        //STR03-C: Since we are specifying the size and already checked the SRC size, the string will not be truncated
        //STR07-C: We are using strncpy to make extra sure to avoid overflows
        strncpy(a->firstName, newFirstName, fstNameLength);
    }else{
        /**
         * @brief Example of rule FIO30-C. Exclude user input from format strings.
         * 
         * The user input string is passed as an argument to fprintf so it will not be executed and the potential 
         * vulnerability of malicious input is avoided altogether
         */
        fprintf(stderr,"ERROR: New username %s has %ld characters and exceeds the max username length of %d characters.\n",newFirstName, fstNameLength, MAX_STRING_LENGTH);
    }
    free(newFirstName);
    //Last name change:
    char* newLastName = (char *) malloc(sizeof(char)*MAX_STRING_LENGTH);
    printf("Enter New Last Name:\n");
    scanf("%s", newLastName);
    size_t lstNameLength = strlen(newLastName);
    if(lstNameLength < (MAX_STRING_LENGTH-1)) {
        strncpy(a->lastName, newLastName, lstNameLength);
    }else{
        fprintf(stderr,"ERROR: New username %s has %ld characters and exceeds the max username length of %d characters.\n",newLastName, lstNameLength, MAX_STRING_LENGTH);
    }
    free(newLastName);
}
/**
 * Change an account's username
 * @param a Changes username of account
 */
void changeUsername(account *a){
    char * newUsername = (char *) malloc(sizeof(char)*MAX_STRING_LENGTH);
    printf("Enter New Username:\n");
    scanf("%s", newUsername);
    //Copies contents of new first name to account's username parameter
    /**
     * @brief Example of rule: ARR38-C. Guarantee that library functions do not form invalid pointers
     * 
     * Before copying the new string the length of the user input must first be checked to see if it will fit in the destination.
     */
    size_t usrNameLength = strlen(newUsername);
    if(usrNameLength < (MAX_STRING_LENGTH-1)){
        size_t size= sizeof(a->username);
        strncpy(a->username,newUsername,size);
    }
    else{
        fprintf(stderr,"ERROR: New username %s has %ld characters and exceeds the max username length of %d characters.\n",newUsername, usrNameLength, MAX_STRING_LENGTH);
    }
    free(newUsername);
}

/**
 * Change an account's password
 * @param a Changes password of account
 */
void changePassword(account *a){
    //TODO: User input for new password
    char* newPassword = (char *) malloc(sizeof(char)*MAX_STRING_LENGTH);
    //Copies contents of new first name to account's uesrname parameter
    printf("Enter New Password:\n");
    scanf("%s", newPassword);
    /**
     * @brief Example of rule: ARR38-C. Guarantee that library functions do not form invalid pointers
     * 
     * Before copying the new string the length of the user input must first be checked to see if it will fit in the destination.
     */
    size_t passLength = strlen(newPassword);
    if(passLength < (MAX_STRING_LENGTH-1)){
        size_t size= sizeof(a->password);
        strncpy(a->password, newPassword, size);
    }
    else{
        fprintf(stderr,"ERROR: New password %s has %ld characters and exceeds the max username lenght of %d characters.\n",newPassword, passLength, MAX_STRING_LENGTH);
    }
    free(newPassword);
}


/**
 * Checks balance of account
 * @param a Account to check balance of
 * @return Returns balance value
 */
double checkBalance(account *a){
    return a->balance;
}

/**
 * Adds funds to account
 * @param a Account to add to
 * @param amount Amount to add
 */
void addFunds(account *a, float amount){
    /* Error checking for negative amount*/
    feclearexcept(FE_ALL_EXCEPT);
    if(amount < 0){
        fprintf(stderr, "Error trying to had negative funds.\n");
    }
    /** @brief Example of rule: INT30-C. Ensure that unsigned integer operations do not wrap 
     *  Slight adaptation as the rule is talking about integers, but checking that floats don't wrap is also critical to prevent a misrepresentation of data 
     *  
     *  This is a precondition test to see if the operation is possible and will be in the valid range for a float.
    */
    else if((FLT_MAX - amount) < a->balance){
        fprintf(stderr, "ERROR FUNDS COULD NOT BE ADDED: adding amount of %f will exceed maximum account balance.\n", amount);

        /** Example of INT30-C Using Integers.
         *  This is provided to show a concrete example that has the appopriate types.
        */
        int b = 10000;
        int c = 50000;
        if((INT_MAX - b) < c){
            /* Handle error*/
        } 
    }
    else{
    /** @brief Example of rule: EXP30-C. Do not depend on the order of evaluation for the side effects
     *  This does not depend on the order of opeartion so no side effects should affect the code
    */
        a->balance += amount;
        printf("New balance:%f\n",a->balance);
        if(fetestexcept(FE_OVERFLOW)){
            fprintf(stderr,"Error float overflow\n");
        }
        else if(fetestexcept(FE_UNDERFLOW)){
            fprintf(stderr,"Error float underflow\n");
        }
        feclearexcept(FE_ALL_EXCEPT);
    /** @brief Example of recommendation: LP03-C. Detect and handle floating-point errors
     *  fetestexcept will detect and handle any floating poiutn error that happens. 
    */
    }
}

/**
 * Withdraw funds from account
 * @param a Account to get money from
 * @param amount Value to withdraw
 * @return Returns value of remaining funds
 */
double withdrawFunds(account *a, unsigned int amount){
    /**
     * @brief Example of rule: INT31-C. Ensure that integer conversions do not result in lost or misinterpreted data
     * 
     * This precondition test is done to ensure that when converted the unsigned int will be in a valid range for the float type.
     * These two conditions ensure that the unsigned int will fall in the (inclusive) range of [FLT_MIN,FLT_MAX] and thus can be represented as a float.
     */
    if(amount <= FLT_MAX && amount >= FLT_MIN){
        // now that we've done the precondition test, can convert it to float type
        float floatAmt = (float) amount;

        // Another example of rule INT30-C: Ensuring that an underflow won't occur:
        if((FLT_MIN+floatAmt) < a->balance){

            // In a valid range so we can safely update the value
            a->balance = a->balance - floatAmt;
        }
        else{ // Failed precondition test: An underflow will occur if funds withdrawn, so reporting the error
            fprintf(stderr, "ERROR FUNDS COULD NOT BE WITHDRAWN: Subtracting amount of:%u will exceed minimum account balance.\n", amount);
        }
    }
    // Failed precondition test: Integer conversion will result in a lost of data, so  reporting the error
    else{
        fprintf(stderr, "ERROR cannot convert %u to a float value.\n", amount);
    }
    return a->balance;
}




/**
 * Prints contents of account
 * @param a Account to print info of
 */
void printAccount(account *a){
    //STR32-C: Since these strings are null terminated, we can use them here without worry of overflow
    printf("First name: %s\n", a->firstName);
    printf("Last name: %s\n", a->lastName);
    printf("Username: %s\n", a->username);
    printf("Password: %s\n", a->password);
    printf("Balance: %f\n", a->balance);
    printf("Account ID: %d\n", a->accountID);
}

/**
 * Get method
 * @param a Account to get accountID from
 * @return Returns accountID
 */
int getAccountID(account *a){
    return a->accountID;
}
