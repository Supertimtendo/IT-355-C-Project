/**
 * @file account.h
 * @author Tim Buranicz
 * @version 1.0
 * Header file for account.c
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct account{
    char* username;
    char* password;
    int balance;
};

void changeUsername(char* newName);
void changePassword(char* oldPswd, char* newPswd);
int checkBalance();

#endif //ACCOUNT_H
