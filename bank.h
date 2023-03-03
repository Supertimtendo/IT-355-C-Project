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

account findAccount(bank b, int accID);
void intializeAccounts(bank b);
void freeAccounts(bank b);
void addAccount(bank b); // creates account and adds it to the array of accounts
void updateAccount(bank b); // prompts user for information about updating their account
bool fundsAvailiable(account a, double amount);
void transferFunds(bank b);
void deposit(bank b);
void withdrawl(bank b);

#endif //BANK_H
