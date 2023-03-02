/**
 * @file main.c
 * @author Tim Buranicz
 * @version 1.0
 * Main file to run
 */
#include "account.h"
#include "bank.h"
#include <stdlib.h>
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
    bank isuBank;
    isuBank.maxAccounts = MAX_NUM_ACCOUNTS;
    isuBank.curAccountCount = 0;

    
    /**
     * @brief Example of recommendation: MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
     * 
     * C is a memory-unsafe language so the mismangment of memory is common and can lead to freeing memory multiple times leading to undefined behavior.
     * 
     * To combat whenever you declare memory in C you should have no expectation that someone else will free it.
     * This is generally implemented by declaring and freeing memory within the same function (or same layer of abstraction).
     */
    intializeAccounts(isuBank);
    // To stuff with the bank, get user input etc.

    // In the same layer of abstraction (the main method), thus succesfully implementing the rule.
    freeAccounts(isuBank);
    return 0;
}