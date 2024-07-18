// Program to find the topological sorting of a graph

#include <stdio.h>
#include <stdlib.h>

int indegree[10], n, cost[10][10];

void calculate()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        indegree[i]=0;
        for(j=0;j<n;j++)
            indegree[i] += cost[j][i];
    }
}

void SourceRemoval()
{
    int i,count;
    int removed[10]={0};
    printf("Topogoical order is:\n");
    for(count=0;count<n;count++)
    {
        calculate();
        for(i=0;i<n;i++)
        {
            if((indegree[i]==0) && (removed[i]==0))
                break;
        }
        if(i==n)
        {
            printf("\nGraph is cyclic\nHence no solution\n");
            return;
        }
        printf("%d ",i);
        removed[i]=1;
        for(int k=0;k<n;k++)
            cost[i][k]=0;
    }
    printf("Above is the correct solution\n");
}

int main()
{
    int i,j;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    SourceRemoval();
    return 0;
}