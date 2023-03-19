#include <stdio.h>
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
   
    printf("hello");

  // Simple Check if fclose is closing problem without errors. If it ever equal EOF I would run handle any erroor that happens. For now I am just detecting them.
   if  (fclose(stdout) == EOF)
   {
     printf("error when claoding stream");
   }
    return 0;
}