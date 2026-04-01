#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

int parent[20];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}

int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[], int n, int e) {
    int i;
    int count = 0;
    int totalWeight = 0;

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, e, sizeof(edges[0]), compare);

    printf("Edges in MST:\n");

    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d \t %d\n", u, v, edges[i].weight);
            unionSet(u, v);
            totalWeight += edges[i].weight;
            count++;
        }
    }

    printf("\nTotal cost of MST = %d\n", totalWeight);
}

int main() {
    int n, e, i;
    struct Edge edges[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskal(edges, n, e);

    return 0;
}
