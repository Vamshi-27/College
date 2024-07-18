// Bubble sort program

#include <stdio.h>
#include<lpc214x.h>

int main()
{
    unsigned int i,j;
    unsigned char a[]={5,1,4,2,3};
    unsigned char temp;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return 0;
}