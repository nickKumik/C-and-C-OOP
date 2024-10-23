
#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"


int main(int argc , char* argv[])
{
    char* cnum = argv[1];
    if (cnum == NULL)
    {
        printf("Please enter a number");
        return 0;
    }else{
        int num = atoi(cnum);
        int result = fibonacci(num);
        printf("Fibonacci of %d = %d", num, result);        
    }
}