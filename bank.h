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
    transactionInfo *transactions; // array of transactions 
}bank;

typedef struct{
  int transactionsTo; 
  int transactionsFrom;
  double transactionAmt;
} transactionInfo;


account createAccount(char* username, char* password, double startingBalance); // creates account and adds it to the array of accounts
account updateAccount(account a); // prompts user for information about updating their account
bool fundsAvailiable(account a, double amount);
bool transferFunds(account from, account to, double transactionAmt);
void deposit(account a, double amount);
bool withdrawl(account a, double amount);

#endif //BANK_H
