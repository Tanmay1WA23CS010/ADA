#include <stdio.h>
#define INF 9999
#define MAX 20

int cost[MAX][MAX];

void prim(int n) {
    int selected[MAX] = {0};
    int edges = 0;
    int minCost = 0;

    selected[0] = 1; // Start with vertex 0

    printf("Edges in the Minimum Cost Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            // Print using 1-based indexing
            printf("%d - %d : %d\n", u + 1, v + 1, cost[u][v]);
            selected[v] = 1;
            minCost += cost[u][v];
            edges++;
        }
    }

    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = INF;

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--; v--; // Convert to 0-based index
        cost[u][v] = cost[v][u] = w;
    }

    prim(n);
    return 0;
}
