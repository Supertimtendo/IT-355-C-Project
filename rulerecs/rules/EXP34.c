#include <stdio.h>
void checkNull(const char* p)
{
  //checking if the p is null or not 
  if(p == NULL)
  {
   printf("NULL Value \n"); 
  }
  else
  {
    printf(" non NULL Value \n"); 
  }
}


int main() {
  char p;
  checkNull(p);
  return 0;
}