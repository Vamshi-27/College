//DPKnapsack problem using dynamic programming

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}

void dp(int n,int m,int p[],int w[])
{
    int v[n+1][m+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                v[i][j]=0;
            else if(j<w[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
            
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    printf("Optimal profit=%d\n",v[n][m]);
    printf("Selected elements are:\t");
    while(m!=0)
    {
        if(v[n][m]!=v[n-1][m])
        {
            printf("%d\t",n);
            m=m-w[n];
        }
        n--;
    }
}

int main()
{
    int i,j,n,m,*p,*w;
    printf("Enter the no of items:\n");
    scanf("%d",&n);
    printf("Enter the knapsack capacity:\n");
    scanf("%d",&m);

    p=(int*)malloc((n+1)*sizeof(int));
    w=(int*)malloc((n+1)*sizeof(int));
    printf("Enter the weights of items:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the price of items:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);

    dp(n,m,p,w);
}