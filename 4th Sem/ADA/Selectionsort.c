// Sorting the array using selection sort algorithm

#include<stdio.h>
#include<stdlib.h>

int count=0;

void selectionsort(int a[],int n)
{
    int i,j,pos,temp;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(a[j]<a[pos])
                pos=j;
        }
        if(pos!=i)
        {
            temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
        }
    }
}

int main()
{
    int i,n,*a;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        a[i]=rand()%1001;
    selectionsort(a,n);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nBasic operation count=%d\n",count);
    free(a);
}