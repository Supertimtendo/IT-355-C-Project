/**
 * @file ERR33-C.c
 * @author Trevor Murphy
 * @brief ERR33-C Detect and handle standard library errors.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Account{
    char first[15];
    char last[15];
    int id[10];
} Account;

int main(){

    // Creates pointer to account object
    struct Account *acc;

    // Allocates memory for account object
    acc = (struct Account *)malloc(sizeof(*acc));

    // Checks if pointer is null
    if(acc == NULL){}
    else
    {
    // Frees memory for account object if not null
    free(acc);
    }

    return 0;
}