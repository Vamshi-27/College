// Dijkstras Algorithm to find the shortest path from a source vertex to all other vertices

#include<stdio.h>
#include<stdlib.h>

void Dijkstras(int n,int s,int cost[][10])
{
    int i,count,u,v,min;
    int dist[n],visited[n];
    for(i=0;i<n;i++)
    {
        dist[i]=cost[s][i];
        visited[i]=0;
    }
    dist[s]=0;
    visited[s]=1;

    for(count=0;count<n-1;count++)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(dist[i]<min && visited[i]==0)
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        for(v=0;v<n;v++)
        {
            if(visited[v]==0 && cost[u][v]!=999 && dist[v]>dist[u]+cost[u][v])
                dist[v]=dist[u]+cost[u][v];
        }
    }
    printf("The shortest path from\n");
    for(v=0;v<n;v++)
        printf("from %d to %d with distance %d\n",s,v,dist[v]);
}

int main()
{
    int i,j,n,s,cost[10][10];
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    printf("Enter the source vertex:\n");
    scanf("%d",&s);
    Dijkstras(n,s,cost);
}