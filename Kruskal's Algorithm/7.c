//Aim:-To find Minimum cost Spanning Tree of a given undirected graph using Kruskal's algorithm.
//Algorithm:-
Let G = (V,E) be the given graph,with| V| = n
{
    Start with a graph T = (V,∅) consisting of only the Vertices of G and no edges;
    Arrange E in the order of increasing costs;
    for(i=1,i<= n-1,i++)
    {
        Select the next smallest cost edge;
        if the edge connects two different connected components add the edge to T;  
    }
}
//Source Code:- 
#include <stdio.h>
int parent[20],min,mincost=0,ne=1,n,cost[20][20];
int a,b,i,j,u,v;
void main()
{
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=99;
        }
    }
    while(ne<n)
    {
        for(i=1;min=99;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
                while(parent[u])
                {
                    u=parent[u];
                }
                while(parent[v])
                {
                    v=parent[v];
                }
                if(u!=v)
                {
                    printf("%d\t edge \t(%d,%d) = %d\n",ne++,a,b,min);
                    mincost+=min;
                    parent[v]=u;
                }
                cost[a][b]=cost[b][a]=99; // Marking the edge as used
            }
            printf("Minimum cost = %d\n",mincost);
}
    }
}
//Output:-
Enter the number of nodes: 3
Enter the cost matrix:
2 5 7
1 3 9
4 1 8
1	 edge 	(1,2) = 1
2	 edge 	(3,2) = 1
Minimum cost = 2
//