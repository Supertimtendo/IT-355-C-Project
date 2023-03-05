/**
 * @file account.h
 * @author Tim Buranicz
 * @version 1.0
 * Header file for account.c
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#define MAX_STRING_LENGTH 25
#include <stdbool.h>
typedef struct {
    float balance;
    int accountID;
    //This implementation of the strings is necessary since the sizes and values are not known yet
    //const keyword cannot be used since modifying them is a feature
    //STR-30C: This rule must be kept in mind here, as if these are modified directly, then an error will occur
    //Therefore, copying will be used rather than modifying the literal
    char *password;
    char *username;
    char *firstName;
    char *lastName;
} account;

account createAccount();
void changeName(account a);
void changeUsername(account a);
void changePassword(account a);
double checkBalance(account a);
void printAccount(account a);
void addFunds(account a, float amount);
double withdrawFunds(account a, unsigned int amount);
int getAccountID(account a);
bool validatePassword(account a, char* enteredPass);
#endif //ACCOUNT_H
