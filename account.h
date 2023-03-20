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
typedef struct{
    float balance;
    int accountID;
/**
 * STR-30C: Keeping this rule in mind when using these char arrays is important. Since they have no values initialized,
 * it is important to make sure not to modify the strings, but instead only copy them. Additionally, when checking strings, make sure
 * to account for the null termination symbol when copying
 */
 //STR-11-C: We are not initializing any value to these, so this is the best way to handle it
    char *firstName;
    char *lastName;
    char *password;
    char *username;
} account;


account createAccount();
void allocateStrings(account *a);
void freeStrings(account *a);
void changeName(account *a);
void changeUsername(account *a);
void changePassword(account *a);
double checkBalance(account *a);
void printAccount(account *a);
void addFunds(account *a, float amount);
double withdrawFunds(account *a, unsigned int amount);
int getAccountID(account *a);
bool validatePassword(account *a, char* enteredPass);
#endif //ACCOUNT_H
