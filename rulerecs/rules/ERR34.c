#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main () { 
   char input[30];
   char *ptr;
   int output;
   errno = 0;

// reads a input from the user into a char
   printf("Input Number\n:");
   scanf("%s", input);
//Turn the char value into a long interger
   const long number = strtol(input, &ptr,10);
//checks if the long interger is a full number with no letter after it
   if(ptr == input||'\0' != *ptr|| LONG_MIN == number||LONG_MAX == number||ERANGE == errno||number > INT_MAX||number < INT_MIN)
   {
//if it fails a check it's denied 
      printf("Invaild please only add only numbers");
   }
   else{
   //if all checks pass then it will turn the long into a int
   output = (int)number;
   printf("The number is %d\n", output);
   }
   return(0);
}