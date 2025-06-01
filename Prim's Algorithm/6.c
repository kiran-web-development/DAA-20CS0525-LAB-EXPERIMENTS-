//Aim :- To find the minimum cost spanning tree of a undirected graph using Prim's algorithm.
// Algorithm :-
1. Initialize a tree with a single vertex, chosen arbitrarily from the graph.
2. Grow the tree by one edge of the that connect the tree to vertices not yet in the tree,find the minimum weight edge,and transfer it to the tree.
3. Repeat step 2 until all vertices are included in the tree.
// Source Code :-
#include <stdio.h>
int Prim(int g[20][20],int n,int t[20][20])
{
    int u,v,min,mncost;
    int visited[20];
    int i,j,k;
    visited[1] = 1; // Start from the first vertex
    for(k = 2; k <= n; k++)
        visited[k] = 0; // Mark all other vertices as unvisited
    mincost = 0; // Initialize minimum cost
    for(k = 1; k < n; k++)
    {
        min = 99; // Set initial minimum to a large value 
        u=1;
        v=1;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==1)
            {
                for(j=1;j<=n;j++)
                {
                    if(g[i][j] < min)
                    {
                        min = g[i][j];
                        u = i;
                        v = j;
                }
            }
        }
        }
        t[u][v] = t[v][u] = g[u][v]; // Add the edge to the tree
        mincost = mincost + g[u][v]; // Update the minimum cost
        visited[v] = 1; // Mark the vertex as visited
        printf("\n(%d,%d) = %d", u, v, t[u][v]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(visited[i]  && visited[j] )
            g[i][j] = g[j][i] = 99; // Remove the edge from the graph
        }
    }
    return (mincost); // Return the total minimum cost
}
void main()
{
    int n,cost[20][20],t[20][20];
    int mincost,i,j;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
            {
                cost[i][j] = 99;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                t[i][j] = 99; // Initialize
            }
        }
        printf("\nThe order of insertion of edges:");
        mincost = Prim(cost, n, t); // Call Prim's algorithm
        printf("\nThe minimum cost = %d\n\n", mincost);
    }
    //Output:
    Enter the number of nodes: 2
    Enter the cost matrix:
        1 9
    The order of insertion of edges:
    (1,1) = 1
    minimum cost = 1
    The order of insertion of edges:
    (1,2) = 9
    minimum cost = 9
    //    