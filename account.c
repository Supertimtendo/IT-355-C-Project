/**
 * @file account.c
 * @author Tim Buranicz
 * @version 1.0
 * Implementation of account
 */
#include <stdio.h>
#include <string.h>
#include "account.h"
#include <float.h>
#include <limits.h>
struct account createAccount(){
    //TODO: Add User input for values
    /**
    char firstName[] = "TEMP";
    char lastName[] = "TEMP";
    char username[] = "TEMP";
    char password[] = "TEMP";
     */

    struct account person;
    return person;
}
/**
 * Change an account's name
 * @param a Changes name of account
 */
void changeName(struct account a){
    //TODO: User input for new names
    char newFirstName[] = "FILLER";
    //Copies contents of new first name to account's first name parameter
    strcpy_s(a.firstName,strlen(a.firstName), newFirstName);
    char newLastName[] = "FILLER";
    //Copies contents of new first name to account's last name parameter
    strcpy_s(a.lastName,strlen(a.lastName), newLastName);
}
/**
 * Change an account's username
 * @param a Changes username of account
 */
void changeUsername(struct account a){
    //TODO: User input for new username
    char newUsername[] = "FILLER";
    //Copies contents of new first name to account's uesrname parameter

    //TODO: Validiate arguments before passing them to the function (will be done by Tom Freier after code for user input is implemented)
    strcpy_s(a.username,strlen(a.username), newUsername);
}

/**
 * Change an account's password
 * @param a Changes password of account
 */
void changePassword(struct account a){
    //TODO: User input for new password
    char newPassword[] = "FILLER";
    //Copies contents of new first name to account's uesrname parameter
    strcpy_s(a.password,strlen(a.password), newPassword);
}
/**
 * Checks balance of account
 * @param a Account to check balance of
 * @return Returns balance value
 */
double checkBalance(struct account a){
    return a.balance;
}

/**
 * Adds funds to account
 * @param a Account to add to
 * @param value Amount to add
 */
void addFunds(struct account a, float amount){
    /* Error checking for negative amount*/
    if(amount < 0){
        fprintf(stderr, "Error trying to had negative funds.\n")
    }
    /** @brief Example of rule: INT30-C. Ensure that unsigned integer operations do not wrap 
     *  Slight adaptation as the rule is talking about integers, but checking that floats don't wrap is also critical to prevent a misrepresentation of data 
     *  
     *  This is a precondition test to see if the operation is possible and will be in the valid range for a float.
    */
    else if((FLT_MAX - amount) < a.balance){
        fprintf(stderr, "ERROR FUNDS COULD NOT BE ADDED: adding amount of %f will exceed maximum account balance.\n", amount);

        /** Example of INT30-C Using Integers.
         *  This is provided to show a concrete example that has the appopriate types.
        */
        int a = 10000;
        int b = 50000;
        if((INT_MAX - a) < b){
            /* Handle error*/
        } 
    }
    else{
        a.balance = a.balance + amount; 
    }
}

/**
 * Withdraw funds from account
 * @param a Account to get money from
 * @param amount Value to withdraw
 * @return Returns value of remaining funds
 */
double withdrawFunds(struct account a, unsigned int amount){
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
        if((FLT_MIN+floatAmt) < a.balance){

            // In a valid range so we can safely update the value
            a.blance = a.balance - floatAmt;
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
void printAccount(struct account a){
    printf(a.firstName);
    printf(a.lastName);
    printf(a.username);
    printf(a.password);
    printf("%f", a.balance);
}

int getAccountID(struct account a){
    return a.accountID;
}