/**
 * @file ENV33.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-09
 * 
 * Shows the proper way to use SEI rule ENV33-C. Do not call system()
 * 
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void executeLSCommand(char *inputDirectory){
  char * args[3] = {"/bin/ls", inputDirectory, NULL}; 
  int status;
  pid_t pid = fork();

  if(pid == -1){ // Error
    /* Handle error */
    fprintf(stderr, "Error creating child process on pid() call. User input: %s\n", inputDirectory);
  }
  elif(pid == 0){ // Child process
    /* Child process calling command to execute*/
    execv(args[0], args); 
  }
  else{ // Parent process
    wait(&status);
    if(status == -1){
      /* Handle error*/
      fprintf(stderr, "Error in parent waiting for child process. User input: %s\n", inputDirectory);
    }
  }
}

int main(){
  char[] userInput = "/home/";
  executeLSCommand(userInput);
}