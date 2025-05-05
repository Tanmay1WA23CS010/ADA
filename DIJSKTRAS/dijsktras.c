#include <stdio.h>
#define MAX 9999  // A large number representing infinity

// Function to implement Dijkstra's Algorithm
void Dijkstra(int n, int cost[n][n], int source, int destination, int d[], int p[]) {
    int S[n];  // Set of vertices for which the shortest distance is known
    int u, v, min;

    // Step 1: Initialization
    for (int i = 0; i < n; i++) {
        S[i] = 0;  // Set all vertices as not in the shortest path set
        d[i] = cost[source][i];  // Initialize distances to the source vertex
        p[i] = source;  // Initialize predecessors
    }

    // Step 2: Add source to the set S
    S[source] = 1;

    // Step 3: Main loop to find the shortest path
    for (int i = 0; i < n - 1; i++) {
        min = MAX;
        u = -1;

        // Find the vertex u such that d[u] is minimum and u is not in S
        for (v = 0; v < n; v++) {
            if (S[v] == 0 && d[v] <= min) {
                min = d[v];
                u = v;
            }
        }

        // If no vertex is found, return (no path exists)
        if (u == -1) {
            printf("No path exists.\n");
            return;
        }

        // Add vertex u to the set S
        S[u] = 1;

        // If we reached the destination, break out
        if (u == destination) {
            break;
        }

        // Update the distances of the neighbors of u
        for (v = 0; v < n; v++) {
            if (S[v] == 0 && cost[u][v] != MAX) {
                if (d[u] + cost[u][v] < d[v]) {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                }
            }
        }
    }

    // Print the shortest path
    printf("Shortest path from %d to %d:\n", source, destination);
    int path[n];
    int count = 0;
    u = destination;

    // Backtrack to find the path
    while (u != source) {
        path[count++] = u;
        u = p[u];
    }
    path[count++] = source;

    // Print the path
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    // Print the shortest distance
    printf("Shortest distance: %d\n", d[destination]);
}

int main() {
    int n, m, source, destination;

    // Input number of nodes and edges
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize the cost matrix (adjacency matrix) with infinity
    int cost[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = MAX;  // Set all costs to infinity
        }
    }

    // Input the edges and their weights
    printf("Enter the edges (u v w) where u and v are nodes and w is the weight:\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;  // Set the weight for edge u-v
        cost[v][u] = w;  // If undirected, set the weight for edge v-u
    }

    // Input the source and destination nodes
    printf("Enter source and destination: ");
    scanf("%d %d", &source, &destination);

    // Arrays to store distances and predecessors
    int d[n];  // Distance array
    int p[n];  // Predecessor array

    // Run Dijkstra's Algorithm
    Dijkstra(n, cost, source, destination, d, p);

    return 0;
}
