//Aim:-To print all the nodes reachable from a given starting node in a directed graph using BFS method.
// Algorithm:-
1.Start from node s.
2.Visit all of neighbors of node s.
3.Then visit all of their unvisited neighbors,if not already visited.
4.Continue until all nodes visited.
// Source Code:-
#include <stdio.h>
#define size 20
#define true 1
#define false 0
int queue[size], visit[20],rear = -1, front = 0;
int n,s,adj[20][20],flag = 0;
void insert q(int v) {
    queue[++rear] = v;
}
void delete q() {
    return(queue[front++]);
}
int q empty() {
    if (rear < front) {
        return 1;
    } else {
        return 0;
    }
    Void bfs(int v) {
    int w;
    visit[v] = 1;
    insert q(v);
    while (!q empty()) {
        v = delete q();
        for(w = 1; w <= n; w++) {
            if (adj[v][w] == 1 && visit[w] == 0) {
                visit[w] = 1;
                flag = 1;
                printf("v%d\t", w);
                insert q(w);
            }
        }
    }
}
void main() {
    int v,w;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(v = 1; v <= n; v++) {
        for(w = 1; w <= n; w++) {
            scanf("%d", &adj[v][w]);
        }
    printf("Enter the start vertex: ");
    scanf("%d", &s);
    printf("Reachability of vertex %d\n", s);
    for(v = 1; v <= n; v++) {
        visit[v] = 0; // Initialize all vertices as not visited
    }
    bfs(s);
    if (flag == 0) {
        printf("No path found !!\n");
    }

// Output:
        Enter the number of vertices:3
        Enter the adjacency matrix:
            2 4 5
            1 4 1
            5 3 1
        Enter the start vertex: 2 4 5
        Reachability of vertex 2
        v1	v3
//

