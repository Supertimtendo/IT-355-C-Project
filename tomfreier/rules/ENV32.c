/**
 * @file ENV32.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-09
 * 
 * Shows the proper way to use SEI rule ENV32-C. All exit handlers must return normally 
 * 
 * Exit handlers are registered with the atexit() function and are called at a normal program termination.
 * Typically, they are used to clean up the program and free up system resources.
 * 
 * This rule states that terminating a call to an exit handler can only be done by returning.
 * If an exit handler where to terminate in any other way undefined behavior will occur potentially resulting in abnormal termination of a program and preventing other exit handlers to be called. 
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * Example of a safe exit handler.
*/
void exit1(){
    printf("Inside exit handler 1.\nDoing typical program cleanup stuff so that program can terminate safely.\n");

    /* Code to cleanup stuff */
    return;
}

/**
 * Example of an unsafe exit handler.
*/
void exit2(){
    printf("Inside eixt handler 2.\n");
    /* DO NOT DO THIS, you should NEVER call exit from within an exit handler
      This nested exit call then will cause the exit handlers to be called again, and could result in undefined behavior. 
    */
    // exit(1); 
    
    
    /* Code to cleanup stuff */
    return;
}

/**
 * @brief Main function that registers two exit handlers and then exits with an error code.
 * 
 * 
*/
int main(void){
    if (atexit(exit1) != 0){
        /* Handle some error*/
        fprintf(stderr, "Error from exit handler: exit1 call.\n");
    }
    if (atexit(exit2) != 0){
        /* Handle some error*/
        fprintf(stderr, "Error from exit handler: exit2 call.\n");
    }
    return 0;
}