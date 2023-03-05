/**
 * @file account.c
 * @author Tim Buranicz, Tom Freier
 * @version 1.0
 * Implementation of account
 */
#include <stdio.h>
#include <string.h>
#include "account.h"
#include <float.h>
#include <limits.h>

/**
 * Method to take in info that is then stored in an account struct
 * @return Returns created struct
 */
account createAccount(){
    //TODO: Add User input for initial values
    //TODO: Make sure inputs are less than (MAX_STRING_LENGTH -1)
    //TODO: Maybe change struct to take parameters?
    account person;
    return person;
}
/**
 * Change an account's name
 * @param a Changes name of account
 */
void changeName(account *a){
    //TODO: User input for new names
    char newFirstName[] = "FILLER";
    size_t fstNameLength = strlen(newFirstName);
    //STR31-C: Checks for enough space prior to copying
    if(fstNameLength < (MAX_STRING_LENGTH-1)) {
        //Copies contents of new first name to account's first name parameter
        //This uses the secure and narrow version of the function strcpy
        strcpy_s(a->firstName, sizeof(a->firstName), newFirstName);
    }
    char newLastName[] = "FILLER";
    size_t lstNameLength = strlen(newLastName);
    //STR31-C: Checks for enough space prior to copying
    if(lstNameLength < (MAX_STRING_LENGTH-1)) {
        //Copies contents of new first name to account's last name parameter
        strcpy_s(a->lastName, sizeof(a->lastName), newLastName);
    }
}
/**
 * Change an account's username
 * @param a Changes username of account
 */
void changeUsername(account *a){
    //TODO: User input for new username
    char newUsername[] = "FILLER";
    //Copies contents of new first name to account's username parameter

    /**
     * @brief Example of rule: ARR38-C. Guarantee that library functions do not form invalid pointers
     * 
     * Before copying the new string the length of the user input must first be checked to see if it will fit in the destination.
     */
    size_t usrNameLength = strlen(newUsername);
    //STR31-C: Checks for enough space prior to copying
    if(usrNameLength < (MAX_STRING_LENGTH-1)){
        printf("True");
        size_t size= sizeof(a->username);
        strcpy_s(a->username,sizeof(a->username),newUsername);
    }
    else{
        fprintf(stderr,"ERROR: New username %s has %ld characters and exceeds the max username lenght of %d characters.\n",newUsername, usrNameLength, MAX_STRING_LENGTH);
    }
    
}

/**
 * Change an account's password
 * @param a Changes password of account
 */
void changePassword(account *a){
    //TODO: User input for new password
    char newPassword[] = "FILLER";
    //Copies contents of new first name to account's uesrname parameter

    /**
     * @brief Example of rule: ARR38-C. Guarantee that library functions do not form invalid pointers
     * 
     * Before copying the new string the length of the user input must first be checked to see if it will fit in the destination.
     */
    size_t passLength = strlen(newPassword);
    //STR31-C: Checks for enough space prior to copying
    if(passLength < (MAX_STRING_LENGTH-1)){
        size_t size= sizeof(a->password);
        strcpy_s(a->password,size, newPassword);
    }
    else{
        fprintf(stderr,"ERROR: New password %s has %ld characters and exceeds the max username lenght of %d characters.\n",newPassword, passLength, MAX_STRING_LENGTH);
    }
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
        a->balance = a->balance + amount;
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
}




/**
 * Prints contents of account
 * @param a Account to print info of
 */
void printAccount(account *a){
    printf("First name: %s\n", a->firstName);
    printf("Last name: %s\n", a->lastName);
    printf("Username: %s\n", a->username);
    printf("Password: %s\n", a->password);
    printf("Balance: %f\n", a->balance);
}

int getAccountID(account *a){
    return a->accountID;
}