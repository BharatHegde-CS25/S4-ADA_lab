#include <stdio.h>
#define V 10
#define INF 9999

int minKey(int key[], int visited[], int n) {
    int min = INF, min_index = -1, i;
    for(i = 0; i < n; i++) {
        if(visited[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims(int graph[V][V], int n) {
    int parent[V], key[V], visited[V];
    int i, count, v, u, total = 0;
    for(i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for(count = 0; count < n-1; count++) {
        u = minKey(key, visited, n);
        visited[u] = 1;
        for(v = 0; v < n; v++) {
            if(graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for(i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", total);
}

int main() {
    int n, i, j;
    int graph[V][V];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    prims(graph, n);
    return 0;
}
