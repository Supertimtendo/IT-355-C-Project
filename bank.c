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

/**
 * @brief Initializes the memory to store all accounts in a bank.
 * 
 * This function uses dynamically allocated memory for the accounts array and follows the recommendations in INT01-C and MEM35-C.
 * 
 * @param b The bank whose accounts are to be initialized.
 */
void initializeAccounts(bank b)
{
  /**
   * @brief Example of recommendation: INT01-C and MEM35-C
   * INT01-C - Use rsize_t or size_t for all integer values representing the size of an object
   *
   * The size of an object should NOT be represented using an short, int, or other integer types as they may not be large enough to represent the size of the object.
   * Thus, the size_t is the correct type for representing the size of the object as it is guaranteed to be large enough to represent the size of an object in memory.
   *
   * MEM35-C - Allocate sufficient memory for an object
   * TODO: @Trevor Murphy please add some documentation describing why this follows your rule
   */
  size_t accountSize = sizeof(account);                    // Size of an account
  size_t allAccountsSize = accountSize * MAX_NUM_ACCOUNTS; // Total size in memory to store all the accounts

  b.accounts = (account *)malloc(allAccountsSize); // dynamically declaring memory for the accounts array
}

/**
 * @brief Frees the memory used to store the accounts in a bank
 * @param b The bank whose accounts are to be freed 
 */
void freeAccounts(bank b)
{
  //TODO: check for errors related to this free call @Trevor Murphy
  free(b.accounts); 
  b.curAccountCount = 0;
  b.maxAccounts = 0;
}

/**
 * @brief Creates an account and and adds it to the array of accounts
 * 
 * @param b The bank to add the account too.
 */
void addAccount(bank b)
{
  if ((b.curAccountCount) < b.maxAccounts)
  {
    b.accounts[b.curAccountCount] = createAccount();
    b.curAccountCount = b.curAccountCount + 1;
  }
  else{
    fprintf(stderr,"ERROR: Maximum account limit of %d was reached for the bank. Account could NOT be added.\n", b.maxAccounts);
  }
}

/**
 * @brief Prompts the user for information about updating their account
 * 
 * @param b The bank that account is in. 
 */
void updateAccount(bank b)
{
  printf("Input Account ID\n:");
  int accID;
  char *userInput;
  /**
   * TODO: Make this code follow rule ERR34-C. Detect errors when converting a string to a number
   * @Tim Lewis
   * 
   */
  if (scanf("%d", accID) < 0)
  { // invalid input from user
    fprintf(stderr, "ERROR did not enter integer.\n");
  }
  else
  { // valid input from user
    account foundAcc = findAccount(b, accID);
    if (foundAcc.accountID == -1)
    { // no account was found
      fprintf(stderr, "ERROR no account with id %d found.\n", accID);
    }
    else
    { 
      changeName(foundAcc);
      changeUsername(foundAcc);
      changePassword(foundAcc);
    }
  }
}

/**
 * @brief Searches for an account in a given bank with the provided account ID.
 * 
 * @param b  The bank to search for the account in.
 * @param accID The ID of the account to search for.
 * @return The account with the provided account ID if found, otherwise a dummy account with a -1 account ID. 
 */
account findAccount(bank b, int accID)
{
  /* Searching for account */
  for (int i = 0; i < b.curAccountCount; i++)
  {
    account curAcc = b.accounts[i];
    if (curAcc.accountID == accID) // Desired account found
    {
      return curAcc;
    }
  }

  // No Account found so returning a dummy account with a -1 account ID
  account dummyAccount;
  dummyAccount.accountID = -1;
  return dummyAccount;
}

// this function could probably be turned into a macro if we need to fit that rule in
bool fundsAvailiable(account a, double amount)
{
  if (amount < 0)
  {
    fprintf(stderr, "Error: trying to check if funds availiable on a negative amount.\n");
    return false;
  }
  else
  {
    bool availiable = ((a.balance - amount) >= 0);
    return availiable;
  }
}

/**
 * Transfer cash from one account to another

 */
void transferFunds(bank b)
{
  // TODO: get user input for account to send money to, send money from, and amount.
}
void deposit(bank b)
{
  // TODO: get user input for account and amount
}
void withdrawl(bank b)
{
  // ToDO: get user input for account and amount
}