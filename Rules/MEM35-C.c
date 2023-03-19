/**
 * @file MEM35-C.c
 * @author Trevor Murphy
 * @brief MEM35-C Allocate sufficient memory for an object.
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

    // Frees memory for account object
    free(acc);

    return 0;
}