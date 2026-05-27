#include <stdio.h>
#include <stdlib.h>

#define MAX 100


void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int count = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Order: ");
    while (front <= rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;


        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[++rear] = v;
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph contains a cycle. Topological ordering not possible.\n");
    }
}

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n, adj);

    return 0;
}
