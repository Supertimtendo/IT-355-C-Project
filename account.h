/**
 * @file account.h
 * @author Tim Buranicz
 * @version 1.0
 * Header file for account.c
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct account{
    double balance;
    //TODO: Check correct way to intialize these strings
    char* password;
    char* username;
    char* firstName;
    char* lastName;
};

struct account createAccount();
void changeName(struct account a);
void changeUsername(struct account a);
void changePassword(struct account a);
double checkBalance(struct account a);
void printAccount(struct account a);
void addFunds(struct account a, double value);
double withdrawFunds(struct account a, double amount);
void transferFunds(struct account a, struct account b);
#endif //ACCOUNT_H
