// Warshall Algorithm to find the transitive closure of a directed graph

#include<stdio.h>
#include<stdlib.h>

void Warshall(int R[][10],int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("\nR(%d)\n",(k+1));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                R[i][j]=R[i][j] || (R[i][k] && R[k][j]);
                printf("%d ",R[i][j]);
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

    int R[10][10];
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&R[i][j]);

    Warshall(R,n);
}