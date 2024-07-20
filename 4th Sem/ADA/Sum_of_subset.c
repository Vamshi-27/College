// Finding number of subsets which gives the given sum

#include <stdio.h>
#include <stdlib.h>

static int count=0;
int x[10],w[10],d;

void sum_of_subset(int s,int k,int rem)
{
    int i;
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("\nSubset=%d\n",++count);
        for(i=0;i<=k;i++)
            if(x[i]==1)
                printf("%d  ",w[i]);
    }
    else if(s+w[k]+w[k+1]<=d)
        sum_of_subset(s+w[k],k+1,rem-w[k]);
    if(s+rem-w[k]>=d && s+w[k+1]<=d)
    {
        x[k]=0;
        sum_of_subset(s,k+1,rem-w[k]);
    }
}

int main()
{
    int sum=0,n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    printf("Enter the required sum\n");
    scanf("%d",&d);
    if(sum<d || d<w[0])
    {
        printf("No subset possible\n");
    }
    else
    {
        sum_of_subset(0,0,sum);
        if(count==0)
            printf("No subset possible\n");
    }
}