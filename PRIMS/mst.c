#include <stdio.h>
#include <limits.h>

void prims(int Adj[][100], int n) {
    int visited[n];
    int totalWeight = 0;

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start with vertex 0 (assuming vertices are 0-indexed)
    visited[0] = 1;
    int edgesAdded = 0;

    printf("Minimum Spanning Tree Edges:\n");
    printf("Edge\tWeight\n");

    while (edgesAdded < n - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        // Find the minimum edge from the visited to unvisited vertices
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && Adj[i][j] > 0 && Adj[i][j] < min) {
                        min = Adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            visited[v] = 1;
            totalWeight += min;
            edgesAdded++;
            printf("%d - %d\t%d\n", u, v, min);
        } else {
            printf("No MST exists (graph is disconnected)\n");
            return;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int Adj[100][100] = {0};

    printf("Enter the edges as v1 v2 weight (enter -1 to stop)\n");
    printf("Note: Vertices should be numbered from 0 to %d\n", n-1);

    while (1) {
        int v1, v2, weight;
        scanf("%d", &v1);
        if (v1 == -1) break;
        scanf("%d %d", &v2, &weight);

        if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
            Adj[v1][v2] = weight;
            Adj[v2][v1] = weight;
        } else {
            printf("Invalid vertex! Vertices must be between 0 and %d\n", n-1);
        }
    }

    prims(Adj, n);

    return 0;
}
