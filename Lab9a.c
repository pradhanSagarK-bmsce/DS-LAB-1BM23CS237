// bfs

#include <stdio.h>

void bfs(int adj[10][10], int n, int source){
    int que[10];
    int front=0,rear=-1;
    int visited[10]={0};
    int node;
    printf("The nodes visited from %d: ", source);
    que[++rear]=source;
    visited[source]=1;
    printf("%d",source);
    while(front<=rear){
        int u= que[front++];
        for(int v=0; v<n; v++){
            if(adj[u][v]==1){
                if(visited[v]==0){
                    printf("%d",v);
                    visited[v]=1;
                    que[++rear]=v;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int adj[10][10];
    int source;
    printf("enter number of nodes \n");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(source=0; source<n; source++){
        bfs(adj,n,source);
    }

    return 0;
}

/*
OUTPUT :
 
 enter number of nodes 
5
Enter Adjacency Matrix 
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
The nodes visited from 0: 01324
The nodes visited from 1: 10243
The nodes visited from 2: 21304
The nodes visited from 3: 30241
The nodes visited from 4: 41302


*/