/**
 * @file MEM06-C.c
 * @author Trevor Murphy
 * @brief MEM06-C. Ensure that sensitive data is not written out to disk
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){

    char *password;
    password = (char *)VirtualAlloc(0, 10, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    // Check if memory allocation was successful
    if(!password){
        printf("Memory allocation failed\n");
        return 0;
    }

    // Lock data
    if(!VirtualLock(password,10)){
        printf("Memory lock failed\n");
        return 0;
    }

    /**
     * Perform operations on password 
     */

    SecureZeroMemory(password,10);
    // Unlock data
    if(!VirtualUnlock(password,10)){
        printf("Memory unlock failed\n");
        return 0;
    }
    VirtualFree(password,0,MEM_RELEASE);
    password = NULL;

    return 0;
}