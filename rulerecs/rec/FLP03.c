#include <stdio.h>
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
   
    double num1 = 10;
    double num2, num3;
    unsigned int rv = _clearfp();
    num2 = num1/0;
    //_clearfp() is decting the floating point erroe of diving by zero and telling it the program to put infinte and not throw an error and possibley crash
    rv = _clearfp();

    num3 = num1 * 0.2;
    rv = _clearfp();

    printf("Num2 = %lf", num2);
    printf("\nNum3 = %lf", num3);
    return 0;
}