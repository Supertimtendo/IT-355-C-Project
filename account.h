/**
 * @file account.h
 * @author Tim Buranicz
 * @version 1.0
 * Header file for account.c
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#define MAX_STRING_LENGTH 25
typedef struct {
    float balance;
    int accountID;
    //TODO: Check correct way to intialize these strings
    char password[MAX_STRING_LENGTH];
    char username[MAX_STRING_LENGTH];
    char firstName[MAX_STRING_LENGTH];
    char lastName[MAX_STRING_LENGTH];
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

#endif //ACCOUNT_H
