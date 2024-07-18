// Case conversion of characters uppercase to lowercase and lowercase to uppercase

#include<stdio.h>
#include<lpc214x.h>

int main()
{
    unsigned char ch='a';
    if(ch>='A' && ch<='Z')
    {
        PINSEL0=ch;
    }
    else if(ch>='a' && ch<='z')
    {
        PINSEL0=ch;
    }
    else
    {
        PINSEL0=ch;
    }
    return 0;
}