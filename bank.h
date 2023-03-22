/**
 * @file bank.h
 * @author Tom Freier
 * @version 1.0
 * Header file for bank.c
 */

#ifndef BANK_H
#define BANK_H
#include "account.h"
#define MAX_NUM_ACCOUNTS 1000

typedef struct{
    account *accounts; // array of accounts
    int curAccountCount; // current number of accounts
    int maxAccounts; // max number of accounts
}bank;

account findAccount(bank *b, int accID);

// intializeAccounts & freeAccounts are an example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
// Both the methods for allocating/deallocating memory associated to the bank class are in the same module (this class)
void initializeAccounts(bank *b);
void freeAccounts(bank *b); 
void addAccount(bank *b); // creates account and adds it to the array of accounts
void updateAccount(bank *b); // prompts user for information about updating their account
bool fundsAvailable(account a, double amount);
void deposit(bank *b);
void withdrawal(bank *b);

#endif //BANK_H
