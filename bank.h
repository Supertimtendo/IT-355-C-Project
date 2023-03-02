/**
 * @file bank.h
 * @author Tom Freier
 * @version 1.0
 * Header file for bank.c
 */

#ifndef BANK_H
#define BANK_H
#include "account.h"

typedef struct{
    account *accounts; // array of accounts
    int curAccountCount; // current number of accounts
    int maxAccounts; // max number of accounts
}bank;


void intializeAccounts(bank b);
void freeAccounts(bank b);
account createAccount(bank b, char* username, char* password, double startingBalance); // creates account and adds it to the array of accounts
account updateAccount(bank b, account a); // prompts user for information about updating their account
bool fundsAvailiable(account a, double amount);
bool transferFunds(account from, account to, double transactionAmt);
void deposit(bank b);
bool withdrawl(bank b);

#endif //BANK_H
