// Knapsack using Greedy Algorithm

#include<stdio.h>
#include<stdlib.h>

void greedy_knapsack(int n,int m,float p[],float w[])
{
    float max,profit=0;
    int i,k,count;

    for(count=0;count<n;count++)
    {
        max=0;
        for(i=0;i<n;i++)
        {
            if((p[i]/w[i])>max)
            {
                k=i;
                max=p[i]/w[i];
            }
        }
        if(w[k]<=m)
        {
            printf("Item %d with fraction 1 is selected\n",k);
            profit += p[k];
            m -= w[k];
            p[k]=0;
        }
        else
        {
            break;
        }
    }
    printf("Discrete knapsack profit=%f\n",profit);
    float x=m/w[k];
    printf("Item %d with fraction %f is selected\n",k,x);
    profit += p[k]*x;
    printf("Continous knapsack profit=%f\n",profit);
}

int main()
{
    int i,n,m;
    float *p,*w;
    printf("Enter the no of items:\n");
    scanf("%d",&n);
    printf("Enter the knapsack capacity:\n");
    scanf("%d",&m);

    p=(float*)malloc(n*sizeof(float));
    w=(float*)malloc(n*sizeof(float));

    printf("Enter the items:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&p[i]);
    }
    printf("Enter the weights of items:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&w[i]);
    }
    greedy_knapsack(n,m,p,w);
    free(p);
    free(w);
}