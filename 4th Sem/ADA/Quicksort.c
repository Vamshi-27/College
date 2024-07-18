//Sorting the array using quicksort algorithm

#include<stdio.h>
#include<stdlib.h>

static int count=0;

int partition(int a[],int l,int r)
{
    int pivot=a[l];
    int i=l,j=r+1,temp;
    do
    {
        do
        {
            i++;
            count++;
        }
        while(a[i]<pivot && i<r);
        do
        {
            j--;
            count++;
        }
        while(a[j]>pivot && j>l);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    while (i<j);
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
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
    quicksort(a,0,n-1);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("Basic operation count=%d\n",count);
    free(a);
}