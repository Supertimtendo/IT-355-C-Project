/**
 * @file bank.c
 * @author Tom Frieer
 * @version 1.0
 * Implementation of bank
 */
#include <stdio.h>
#include <string.h>
#include "bank.h"
#define MAX_NUM_ACCOUNTS 1000

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
  if(free(b.accounts) < 0){
    fprintf(stderr,"Error in freeing accounts array.\n")
  }
}
// creates account and adds it to the array of accounts
account createAccount(char* username, char* password, double startingBalance){

} 

// prompts user for information about updating their account
account updateAccount(account a){

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
 * @param from SRC account
 * @param to DST account
 * @param transactionAmt amount of funds to be transfered
 */
bool transferFunds(account from, account to, double transactionAmt){
  if(fundsAvailiable(from, transactionAmt)){
    from.balance -= transactionAmt;
    to.balance += transactionAmt;
    return true;
  }
  else{
    fprintf(stderr, "Error in processing transaction from accID: %d to: %d of amount: %f", from.accountID, to.accountID, transactionAmt);
    return false;
  }
}
void deposit(bank b){
  //TO-DO: get user input for account and amount 
}
bool withdrawl(bank b){
  // To-DO: get user input for account and amount
}