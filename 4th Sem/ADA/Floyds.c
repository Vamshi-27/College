// Floyd algorithm to find the shortest path between all pairs of vertices in a graph

#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}

void Floyd(int n,int D[][10])
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("\nD(%d)\n",(k+1));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
                printf("%d ",D[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int i,j,n;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    int D[10][10];
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&D[i][j]);

    Floyd(n,D);
}