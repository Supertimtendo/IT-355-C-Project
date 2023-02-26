/**
 * @file bank.c
 * @author Tom Frieer
 * @version 1.0
 * Implementation of bank
 */
#include <stdio.h>
#include <string.h>
#include "bank.h"

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
void deposit(account a, double amount){
  addFunds(a, amount);
}
bool withdrawl(account a, double amount){
  if(fundsAvailiable(a, amount)){
    withdrawFunds(a, amount);
    return true;
  }
  else{
    return false;
  }
}