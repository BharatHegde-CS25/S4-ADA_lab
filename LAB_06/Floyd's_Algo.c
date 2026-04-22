#include <stdio.h>
#define INF 9999
#define V 10

void floyd(int graph[V][V], int n)
{
    int dist[V][V];
    int i, j, k;

    // Initialize
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Floyd’s algorithm
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Output
    printf("All Pair Shortest Path Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j;
    int graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floyd(graph, n);

    return 0;
}
