/**
 * @file account.c
 * @author Tim Buranicz
 * @version 1.0
 * Implementation of account
 */
#include <stdio.h>
#include <string.h>
#include "account.h"

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

}

/**
 * Change an account's password
 * @param a Changes password of account
 */
void changePassword(struct account a){

}
/**
 * Checks balance of account
 * @param a Account to check balance of
 * @return Returns balance value
 */
double checkBalance(struct account a){

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
