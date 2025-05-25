#include <stdio.h>
#define INF 99999
#define MAX 100

int graph[MAX][MAX], dist[MAX], visited[MAX], parent[MAX];
int n;

// Function to find the vertex with minimum distance
int minDistance() {
    int min = INF, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra's algorithm
void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

// Recursive function to print the path from source to a vertex
void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    printPath(parent[v]);
    printf(" -> %d", v);
}

// Function to print path matrix from source
void printPathMatrix(int src) {
    printf("\nPath Matrix from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Path to %d: ", i);
        if (dist[i] == INF) {
            printf("No path\n");
        } else {
            printPath(i);
            printf(" (Cost: %d)\n", dist[i]);
        }
    }
}

int main() {
    int e, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);
    printf("Enter destination vertex: ");
    scanf("%d", &dest);

    dijkstra(src);

    if (dist[dest] == INF) {
        printf("No path from %d to %d\n", src, dest);
    } else {
        printf("\nShortest distance from %d to %d: %d\n", src, dest, dist[dest]);
        printf("Path: ");
        printPath(dest);
        printf("\n");
    }

    // Print path matrix from the source
    printPathMatrix(src);

    return 0;
}
