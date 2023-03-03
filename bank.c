/**
 * @file bank.c
 * @author Tom Frieer
 * @version 1.0
 * Implementation of bank
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bank.h"

void intializeAccounts(bank b){
  /**
     * @brief Example of recommendation: : INT01-C. Use rsize_t or size_t for all integer values representing the size of an object
     * 
     * The size of an object should NOT be represented using an short, int, or other integer types as they may not be large enough to represent the size of the object.
     * Thus, the size_t is the correct type for representing the size of the object as it is guaranteed to be large enough to represent the size of an object in memory.
     */
    size_t accountSize = sizeof(account); // Size of an account
    size_t allAccountsSize = accountSize * MAX_NUM_ACCOUNTS; // Total size in memory to store all the accounts

    b.accounts = (account *) malloc(allAccountsSize); // dynamically declaring memory for the accounts array
}

void freeAccounts(bank b){
  free(b.accounts);
}
// creates account and adds it to the array of accounts
void addAccount(bank b){
  if((b.curAccountCount+1) < b.maxAccounts){
    b.accounts[b.curAccountCount] = createAccount();
    b.curAccountCount = b.curAccountCount+1; 
  }
}

// prompts user for information about updating their account
void updateAccount(bank b, account a)
{
  
}


account findAccount(bank b, int accID){
  /* Searching for account */
  for(int i=0;i<b.curAccountCount;i++){
    account curAcc = b.accounts[i];
    if(curAcc.accountID == accID){
      return curAcc;
    }
  }

  // No Account found so returning a dummy account with a -1 account ID
  account dummyAccount;
  dummyAccount.accountID = -1;
  return dummyAccount;
}

// this function could probably be turned into a macro if we need to fit that rule in
bool fundsAvailiable(account a, double amount){
  if(amount < 0){
    fprintf(stderr,"Error: trying to check if funds availiable on a negative amount.\n");
    return false;
  }
  else{
    bool availiable = ((a.balance - amount) >= 0); 
    return availiable;
  }
}

/**
 * Transfer cash from one account to another

 */
void transferFunds(bank b){
  //TO-DO: get user input for account to send money to, send money from, and amount.
}
void deposit(bank b){
  //TO-DO: get user input for account and amount 
}
void withdrawl(bank b){
  // To-DO: get user input for account and amount
}