#include <stdio.h>
#define V 10
#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index, i;

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print path
void printPath(int parent[], int j)
{
    if(parent[j] == -1)
    {
        printf("%d", j);
        return;
    }

    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[V][V], int n, int source)
{
    int dist[V], visited[V], parent[V];
    int i, count, v, u;

    // Initialization
    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Find shortest paths
    for(count = 0; count < n - 1; count++)
    {
        u = minDistance(dist, visited, n);
        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;   // store path
            }
        }
    }

    // Output
    printf("Vertex\tDistance\tPath\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int main()
{
    int n, i, j, source;
    int graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}
