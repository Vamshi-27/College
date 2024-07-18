// Factorial of a number

#include <stdio.h>
#include<lpc214x.h>

int main()
{
    unsigned int i;
    unsigned char num=5;
    unsigned long fact=1;
    for(i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    PINSEL0=fact;
    return 0;
}