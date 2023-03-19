#include <stdio.h>

int main() {
  int x,y,z;
  x = 1;
  printf("%d", x);
  //this does folloe the rule as long as it is assiment is intentional and used in the if statement
  // could also just say x !=0 for the same reult but just wants to show that using assiment in an selction statemnt is fine as long as it is intentional 
  if((x=y)!= 0)
  {
    printf("\n%d", y);
    printf("\n%d", x);
    z = x + y;
  }
  printf("\n%d", z);
  return 0;
}