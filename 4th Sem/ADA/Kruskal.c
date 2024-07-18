// Kruskal Algorithm for finding minimum spanning tree

#include<stdio.h>
#include<stdlib.h>

void kruskal(int n,int cost[][10])
{
    int a,b,i,j,u,v,min,totalcost=0,ecounter=0;
    int par[n];

    for(i=0;i<n;i++)
        par[i]=-1;
    
    printf("The minimum spanning tree edges are:\n");
    while(ecounter<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(par[u]!=-1)
            u=par[u];
        while(par[v]!=-1)
            v=par[v];
        
        if(u!=v)
        {
            printf("Edge from %d to %d and the cost is %d\n",a,b,min);
            totalcost += min;
            par[b]=a;
            ecounter++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Total cost=%d\n",totalcost);
}

int main()
{
    int i,j,n,cost[10][10];
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    kruskal(n,cost);
}