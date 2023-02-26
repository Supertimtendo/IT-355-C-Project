/**
 * @file account.h
 * @author Tim Buranicz
 * @version 1.0
 * Header file for account.c
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    double balance;
    int accountID;
    //TODO: Check correct way to intialize these strings
    char* password;
    char* username;
    char* firstName;
    char* lastName;
} account;

struct account createAccount();
void changeName(struct account a);
void changeUsername(account a);
void changePassword(struct account a);
double checkBalance(struct account a);
void printAccount(struct account a);
void addFunds(struct account a, double value);
double withdrawFunds(struct account a, double amount);
int getAccountID(struct account a);

#endif //ACCOUNT_H
