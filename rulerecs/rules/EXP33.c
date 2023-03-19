#include <stdio.h>
/**
 * Main function
 * @return Return 0 for exit success
 */

void setFlag(int number, int *flag)
{
    if(number >= 0)
    {
        *flag = 1;
    }
    else{
        *flag = -1;
    }
}

int main(){
int number = 0;
int flag;

//flag will is set to a vlaue by setflag method.
//setflag will check if the number is postive or negative It checks for evry thing that number can be equal so Flag will never equal a null value
setFlag(number, &flag);

if(flag == 1)
{
    printf("Number is postive.");
}
else if(flag == -1)
{
    printf("Number is negtive.");
}

return 0;
}