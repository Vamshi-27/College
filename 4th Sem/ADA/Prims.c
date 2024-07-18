// Prims algorithm for minimum spanning tree

#include <stdio.h>

void Prims(int n,int s,int cost[][10])
{
    int i,j,a,b,min,totalcost=0,ecounter=0;
    int tvertex[10]={0};
    tvertex[s]=1;
    while(ecounter<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(tvertex[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(tvertex[j]==0 && cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        printf("The edge from %d to %d with cost %d\n",a,b,min);
        tvertex[b]=1;
        totalcost += min;
        ecounter++;
    }
    printf("Mincost=%d\n",totalcost);
}

int main()
{
    int i,j,n,s,cost[10][10];
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter the source vertex:\n");
    scanf("%d",&s);
    Prims(n,s,cost);
}