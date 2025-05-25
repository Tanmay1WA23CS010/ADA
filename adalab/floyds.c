#include <stdio.h>

#define INF 99999
#define MAX 100

int A[MAX][MAX], D[MAX][MAX];
int n, m; // n = number of vertices, m = number of edges

// Initialize adjacency matrix
void initializeMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                A[i][j] = 0;
            else
                A[i][j] = INF;
        }
    }
}

// Build the initial distance matrix from adjacency matrix
void initializeDistanceMatrix() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            D[i][j] = A[i][j];
}

// Floyd-Warshall Algorithm
void floydWarshall() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}

// Print final shortest paths
void printResult() {
    printf("\nAll Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    initializeMatrix(); // Set all edges to INF initially

    printf("Enter each edge in the format: src dest weight (0-based indexing)\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        A[u][v] = w;
    }

    initializeDistanceMatrix(); // Set D = A
    floydWarshall();            // Run Floyd's Algorithm
    printResult();              // Display final matrix

    return 0;
}
