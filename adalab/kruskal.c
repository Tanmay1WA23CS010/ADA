#include <stdio.h>

#define MAX 100

// Define a new type 'Edge' using typedef
typedef struct {
    int u, v, weight;
} Edge;

// Global arrays
Edge edges[MAX], mst[MAX]; // Edge list and MST
int parent[MAX];
int n, m; // Number of vertices and edges

// Function to find the root of a set using path compression
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to unite two disjoint sets
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Sort edges in ascending order of weights using bubble sort
void sortEdges() {
    Edge temp;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

// Kruskal’s algorithm function
void kruskal() {
    int count = 0; // MST edge count
    int sum = 0;   // Total cost of MST

    sortEdges(); // Step 1: Sort all edges

    // Step 2: Initialize each node as its own parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Step 3: Process edges one by one
    for (int i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        int setU = find(u); // Find root of u
        int setV = find(v); // Find root of v

        if (setU != setV) {
            mst[count++] = edges[i]; // Add edge to MST
            sum += w;                // Add weight to total cost
            unionSets(setU, setV);   // Merge the sets
        }
    }

    // Step 4: Print MST result
    if (count == n - 1) {
        printf("\nMST Edges:\n");
        for (int i = 0; i < count; i++)
            printf("%d - %d (Weight: %d)\n", mst[i].u, mst[i].v, mst[i].weight);
        printf("Total Cost: %d\n", sum);
    } else {
        printf("No MST exists (graph is disconnected)\n");
    }
}

// Main function to take input and invoke Kruskal’s algorithm
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter each edge (u v weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(); // Run the algorithm

    return 0;
}
