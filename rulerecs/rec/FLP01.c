#include <stdio.h>
/**
 * Main function
 * @return Return 0 for exit success
 */
int main(){
   
   //shows that floating point can lead to rough approximation of real numbers
    double num1 = 10;
    double num2, num3;
    num2 = num1/5.0;
    num3 = num1 * 0.2;
    printf("Num2 = %lf", num2);
    printf("\nNum3 = %lf", num3);
    return 0;
}