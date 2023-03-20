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
void initializeAccounts(bank *b);
void freeAccounts(bank *b);
void addAccount(bank *b); // creates account and adds it to the array of accounts
void updateAccount(bank *b); // prompts user for information about updating their account
bool fundsAvailable(account a, double amount);
void transferFunds(bank *b);
void deposit(bank *b);
void withdrawal(bank *b);

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
    printf("compilation time is: ", __TIME__);
    return;
}

#endif //BANK_H
