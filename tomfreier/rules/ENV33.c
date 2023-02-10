/**
 * @file ENV33.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-09
 * 
 * Shows the proper way to use SEI rule ENV33-C. Do not call system()
 * Note: This program uses the POSIX execv() function so will only run on POSIX systems. A similiar example using the CreateProcess() command could be used on a Windows machine.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * @brief Executes the /bin/ls command on the specefied directory from user input and prints the results to console.
 * 
 * A child process will be created to run the /bin/ls program.
 * This program will be ran via the execv() function which replaces the current processes's current program image with a new program image.
 * By using the execv() function instead of the command() function, prevents certain attacks that can be caused by a malicious user input.
 * Since the execv() function takes an argument specifying the new program image, it will not be able to execute multiple commands. While the system() function will be vulnerable to such attacks.
 * 
 * 
 * @param inputDirectory The directory to have it's contents printed via the ls command.
*/
void executeLSCommand(char *inputDirectory){
  char * args[3] = {"/bin/ls", inputDirectory, NULL}; 
  int status;
  pid_t pid = fork();

  if(pid == -1){ // Error
    /* Handle error */
    fprintf(stderr, "Error creating child process on pid() call. User input: %s\n", inputDirectory);
  }
  else if(pid == 0){ // Child process
    /* Child process calling command to execute*/
    printf("Running ls command was directory: %s.\n",inputDirectory);
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

/**
 * @brief Main function that calls executeLSCommand with a safe and potentially dangerous command.
 * @return Returns 0 for exit success
*/
int main(){
  printf("Running with a safe command\n");
  char userInput[] = "/home/";
  executeLSCommand(userInput);

  printf("\nRunning with a command that would be dangerous if system() was used.\n");
  char dangerousInput[] = "/home/;rm -r /home/*";
  executeLSCommand(dangerousInput);
}