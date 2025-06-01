//Aim:- To check whether a given graph is connected or not using DFS method.
//Algorithm:-
 DFS(G, v) (V is the vertex where the search starts)
 Stack S:= {}; (start with an empty stack)
 for each vertex u,Set visited[u] := false; 
 push S,v;
 while (S is not empty) do
     u := pop S;
     if not visited[u] then
         visited[u] := true;
         for each vertex w adjacent to u do
             if not visited[w] then
                 push S,w;
                 end if
 end while
 END DFS()
 // Source Code:-
#include <stdio.h>
int visited[20], n,adj[20][20],s,count=0;
void dfs(int v)
{
    int w;
    visited[v] = 1;
    count++;
    for(w = 0; w < n; w++)
    {
        if(adj[v][w] == 1 ) && (visit[w]==0))
        {
            dfs(w);
        }
        void main()
        {
            int v,w;
            printf("Enter the number of vertices: ");
            scanf("%d", &n);
            printf("Enter the adjacency matrix:\n");
            for(v = 1; v < n; v++)
            {
                for(w = 1; w < n; w++)
                {
                    scanf("%d", &adj[v][w]);
                }
                for(v = 1; v < n; v++)
                {
                    visit[v] = 0; // Initialize all vertices as not visited
                }
                dfs(1);
                if(count == n)
                {
                    printf("The graph is connected.\n");
                }
                else
                {
                    printf("The graph is not connected.\n");
                }
            }
        }
    }
}
// Output:
    Enter the number of vertices:
    2
    Enter the adjacency matrix:
    4 1
    The graph is connected.