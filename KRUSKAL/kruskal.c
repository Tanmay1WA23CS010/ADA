#include <stdio.h>

// Structure to represent an edge
typedef struct {
    int u, v, w;
} Edge;

// Function to swap two edges
void swap(Edge *a, Edge *b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort to sort edges by weight
void bubbleSort(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (edges[j].w > edges[j + 1].w) {
                swap(&edges[j], &edges[j + 1]);
            }
        }
    }
}

// Find function for union-find
int find(int parent[], int i) {
    while (parent[i] >= 0) {
        i = parent[i];
    }
    return i;
}

// Union function for union-find
void unionSets(int parent[], int i, int j) {
    if (i != j) {
        if (parent[i] < parent[j]) {
            parent[i] += parent[j];
            parent[j] = i;
        } else {
            parent[j] += parent[i];
            parent[i] = j;
        }
    }
}

// Kruskal's Algorithm to find MST
void kruskal(int n, int m, Edge edges[]) {
    // Step 1: Sort edges by weight using Bubble Sort
    bubbleSort(edges, m);

    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;  // Initialize parent array
    }

    int sum = 0;      // To store the total weight of MST
    int count = 0;    // To count the edges in the MST
    printf("Edges in the MST:\n");

    // Step 2: Process the edges in sorted order
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int set_u = find(parent, u);
        int set_v = find(parent, v);

        // If u and v are in different sets, include this edge in the MST
        if (set_u != set_v) {
            unionSets(parent, set_u, set_v);
            printf("%d -- %d : %d\n", u, v, w);
            sum += w;
            count++;
        }

        // If we already have n-1 edges in the MST, break early
        if (count == n - 1) {
            break;
        }
    }

    // Step 3: Check if MST is formed
    if (count == n - 1) {
        printf("Total cost of MST: %d\n", sum);
    } else {
        printf("No MST exists\n");
    }
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    Edge edges[m];

    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(n, m, edges);

    return 0;
}
