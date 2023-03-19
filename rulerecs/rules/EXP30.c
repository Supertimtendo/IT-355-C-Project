#include <stdio.h>
/**
 * Main function
 * @return Return 0 for exit success
 */

int div(int x){

    return x/2;
}
int add(int x){

    return x + 10;
}
int sub(int x, int y)
{
    return y - x;
}
int main(){
   int x, y;

   int value = 10;
    // Each of this method and do not rely on the order of evauation to work
   x = div(value);
   y = add(value);
   value = sub(x,y);
   printf("%d",value);
   return 0;
}