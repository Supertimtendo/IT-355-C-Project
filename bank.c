/**
 * @file bank.c
 * @author Tom Frieer, Lucas Beebe
 * @version 1.0
 * Implementation of bank
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include "bank.h"
#include "account.h"

/*
* @brief example of PRE01-C. Use parentheses within macros around parameter names
* this macro uses the correct parenthesis around parameters, no practical use in this specific program but the rec example is here
*/
//#define SQUAREMACRO (I) ((I)*(I))
//int squareMacNum = SQUAREMACRO(2);
/*
* @brief example of PRE02-C. Macro replacement lists should be parenthesized
* this macro uses paranthesis around its lists properly, no practical use in this specific program but the rec example is here
*/
//#define SQUAREMACRO (I) ((I)*(I))
//int replList = 5
//int squareMacNum2 = SQUAREMACRO(repList);
/*
* @brief example of PRE12-C. Do not define unsafe macros
* this inline function replaces an unsafe macro, no practical use in this specific program but the rec example is here
*/
static inline int inlineFunc(){
    return 24;
}
/*
* @brief example of  PRE13-C. Use the Standard predefined macros to test for versions and features
* this macro is from the standard testing list, no practical use in this specific program but the rec example is here
*/static inline void inlineFunc2(){
    printf("compilation time is: %s", __TIME__);
    return;
}
/**
 * @brief Initializes the memory to store all accounts in a bank.
 * 
 * This function uses dynamically allocated memory for the accounts array and follows the recommendations in INT01-C and MEM35-C.
 * 
 * @param b The bank whose accounts are to be initialized.
 */
void initializeAccounts(bank *b)
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
  b->curAccountCount = 0;
  b->maxAccounts = MAX_NUM_ACCOUNTS;
  size_t accountSize = sizeof(account);                    // Size of an account
  size_t allAccountsSize = accountSize * MAX_NUM_ACCOUNTS; // Total size in memory to store all the accounts
  if (allAccountsSize < accountSize || allAccountsSize <MAX_NUM_ACCOUNTS){ // post condition check for overflow
    fprintf(stderr,"ERROR: allAccountsSize variable in intializeAccounts overflowed the size_t type.\n");
    exit(1);
  }
  b->accounts = (account *)malloc(allAccountsSize); // dynamically declaring memory for the accounts array
}

/**
 * @brief Frees the memory used to store the accounts in a bank
 * @param b The bank whose accounts are to be freed 
 */
void freeAccounts(bank *b)
{
  for(int i=0;i<b->curAccountCount;i++){
    account a = b->accounts[i];
    freeStrings(&a);
  }
  if(b->accounts != NULL){ // error checking
    free(b->accounts); // MEM31-C
    b->accounts = NULL; // MEM01-C
  }
  b->curAccountCount = 0;
  b->maxAccounts = 0;
}

/**
 * @brief Creates an account and and adds it to the array of accounts
 * 
 * @param b The bank to add the account too.
 */
void addAccount(bank *b)
{
  
  /**
     * @brief Example of rule: EXP45-C. Do not perform assignments in section statements
     * The section statement does not perfrom aassignment
     */
  if ((b->curAccountCount) < b->maxAccounts)
  {
    int curCount = b->curAccountCount; 
    account a = createAccount();
    a.accountID = curCount;
    b->accounts[curCount] = a;
    b->accounts[curCount].accountID = curCount; 
    b->curAccountCount = curCount + 1;
    printf("AccountID:%d\n",a.accountID);

  }
  else{
    fprintf(stderr,"ERROR: Maximum account limit of %d was reached for the bank. Account could NOT be added.\n", b->maxAccounts);
  }
}

/**
 * @brief Prompts the user for information about updating their account
 * 
 * @param b The bank that account is in. 
 */
void updateAccount(bank *b)
{
  printf("Input Account ID\n:");
  errno = 0;
  char *ptr;
  /**
  * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
  */ 
  char *userInputChar = (char *) malloc(sizeof(char) * 100);
  
  /**
   * @brief Example of rule: ERR34-C. Detect errors when converting a string to a number
   * 
   * After reading a char string from the user and coverting it to an int. It must be checked to make sure that the char was converted to an int correctly. 
   * The if statment will check that the int is a non decimal and that there are no letters in it. 
   * 
   * This also properly compares char in the same array object showing an example of 
   * ARR37-C. Do not add or subtract an integer to a pointer to a non-array object
   * ARR39-C. Do not add or subtract a scaled integer to a pointer 
   */
  scanf("%s", userInputChar);
  const long userInputNumber = strtol(userInputChar, &ptr,10); 
  if (ptr == userInputChar||'\0' != *ptr|| LONG_MIN == userInputNumber||LONG_MAX == userInputNumber||ERANGE == errno||userInputNumber > INT_MAX||userInputNumber < INT_MIN)
  { // invalid input from user
    fprintf(stderr, "ERROR did not enter integer.\n");
  }
  else
  { // valid input from user
    // Example of rule INT31 we know this conversion is guranteed since these are both signed types and the long type is wider than the int type.
    int accID = (int) userInputNumber;  
    
    account foundAcc = findAccount(b, accID);
    if (foundAcc.accountID == -1)
    { // no account was found
      fprintf(stderr, "ERROR no account with id %d found.\n", accID);
    }
    else
    { 
      changeName(&foundAcc);
      changeUsername(&foundAcc);
      changePassword(&foundAcc);
    }
  }

  // the memory is free'd in the same module and thus implements the rule.
  if(userInputChar != NULL){ // error checking
    free(userInputChar); // MEM31-C
    userInputChar = NULL; // MEM01-C
  }
}

/**
 * @brief Searches for an account in a given bank with the provided account ID.
 * 
 * @param b  The bank to search for the account in.
 * @param accID The ID of the account to search for.
 * @return The account with the provided account ID if found, otherwise a dummy account with a -1 account ID. 
 */
account findAccount(bank *b, int accID)
{

  /* Searching for account */
  /**
   * @brief Example of rule: EXP33-C. Do not read uninitialized memory
   *  This Code find accoutns that have data and are not null. This follwos the rules of not reading uninitialized memory by only using accoutn with infomation in them
   */
  for (int i = 0; i < b->curAccountCount; i++)
  {
    account curAcc = b->accounts[i];
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
bool fundsAvailable(account a, double amount)
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


void deposit(bank *b)
{
  // TODO: get user input for account and amount
  printf("Input Account ID\n:");
  errno = 0;
  char *ptr;
  int accID;
  /**
  * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
  */ 
  char *userInputChar = (char *) malloc(sizeof(char) * 100);
  
  /**
   * @brief Example of rule: ERR34-C. Detect errors when converting a string to a number
   * 
   * After reading a char string from the user and coverting it to an int. It must be checked to make sure that the char was converted to an int correctly. 
   * The if statment will check that the int is a non decimal and that there are no letters in it. 
   * 
   */
  scanf("%s", userInputChar);
  const long userInputNumber = strtol(userInputChar, &ptr,10);
  if (ptr == userInputChar||'\0' != *ptr|| LONG_MIN == userInputNumber||LONG_MAX == userInputNumber||ERANGE == errno||userInputNumber > INT_MAX||userInputNumber < INT_MIN)
  { // invalid input from user
    fprintf(stderr, "ERROR did not enter integer.\n");
  }
  else
  { // valid input from user
    accID = (int)userInputNumber;
    account foundAcc = findAccount(b, accID);
    if (foundAcc.accountID == -1)
    { // no account was found
      fprintf(stderr, "ERROR no account with id %d found.\n", accID);
    } 
    else
    { 
      printf("Enter a whole number amount to deposit into account:\n");
      scanf("%s", userInputChar);
      const long userInputNumber2 = strtol(userInputChar, &ptr,10);
       /**
     * @brief Example of rule: EXP45-C. Do not perform assignments in section statements
     * The section statement does not perfrom aassignment
     */
      if (ptr == userInputChar|| LONG_MIN == userInputNumber2||LONG_MAX == userInputNumber2||ERANGE == errno||userInputNumber2 > FLT_MAX||userInputNumber2 < FLT_MIN)
      { // invalid input from user
        fprintf(stderr, "ERROR did not enter integer.\n");
      }
      else
      {
      float amount = (float)userInputNumber2;
      addFunds(&foundAcc, amount);
      }

    }
    if(userInputChar != NULL){
      free(userInputChar);
      userInputChar = NULL;
    }
  }
  
}
void withdrawal(bank *b)
{
  // ToDO: get user input for account and amount
  printf("Input Account ID\n:");
  errno = 0;
  char *ptr;
  int accID;
  /**
  * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
  */ 
  char *userInputChar = (char *) malloc(sizeof(char) * 100);
  
  /**
   * @brief Example of rule: ERR34-C. Detect errors when converting a string to a number
   * 
   * After reading a char string from the user and coverting it to an int. It must be checked to make sure that the char was converted to an int correctly. 
   * The if statment will check that the int is a non decimal and that there are no letters in it. 
   * 
   */
  scanf("%s", userInputChar);
  const long userInputNumber = strtol(userInputChar, &ptr,10);
   /**
     * @brief Example of rule: EXP45-C. Do not perform assignments in section statements
     * The section statement does not perfrom aassignment
     */
    // Ex of INT17: Define integer constants in an implementation independent manner:
    // The LONG_MIN and LONG_MAX values are defined in limits.h which will set these values appopriately depending on the compiler and machine the code is executed on.
    // const int MY_INT_MAX = 4294967296 (2^32) would a violation of this rule as the max size of an int will be implementation independent. So instead the values from the limits header should be used. 
  if (ptr == userInputChar||'\0' != *ptr|| LONG_MIN == userInputNumber||LONG_MAX == userInputNumber||ERANGE == errno||userInputNumber > INT_MAX||userInputNumber < INT_MIN)
  { // invalid input from user
    fprintf(stderr, "ERROR did not enter integer.\n");
  }
  else
  { // valid input from user
    accID = (int)userInputNumber;
    account foundAcc = findAccount(b, accID);
    if (foundAcc.accountID == -1)
    { // no account was found
      fprintf(stderr, "ERROR no account with id %d found.\n", accID);
    }
    else
    { 
      printf("Enter amount to withdrawal from account:\n");
      scanf("%s", userInputChar);
      const long userInputNumber2 = strtol(userInputChar, &ptr,10);
       /**
     * @brief Example of rule: EXP45-C. Do not perform assignments in section statements
     * The section statement does not perfrom aassignment
     */
      if (ptr == userInputChar||'\0' != *ptr|| LONG_MIN == userInputNumber||LONG_MAX == userInputNumber||ERANGE == errno||userInputNumber > INT_MAX||userInputNumber < INT_MIN)
      { // invalid input from user
      fprintf(stderr, "ERROR did not enter integer.\n");
      }
      else
      {
      int amount = (int)userInputNumber2;
      withdrawFunds(&foundAcc, amount);
      }
    }
  }
  if(userInputChar != NULL){
    free(userInputChar);
    userInputChar = NULL;
  }
}
