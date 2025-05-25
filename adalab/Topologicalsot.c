#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];       // adjacency matrix
int indegree[MAX];         // indegree array
int stack[MAX];            // stack for vertices with indegree 0
int top = -1;
int n;                    // number of vertices

// Push function for stack
void push(int v) {
    stack[++top] = v;
}

// Pop function for stack
int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Calculate indegree of each vertex
void calculateIndegree() {
    for (int i = 0; i < n; i++) {
        indegree[i] = 0; // initialize
        for (int j = 0; j < n; j++) {
            if (graph[j][i] == 1) {
                indegree[i]++;
            }
        }
    }
}

// Perform topological sort using indegree and stack
void topologicalSort() {
    calculateIndegree();

    // Push all vertices with indegree 0 into stack
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            push(i);
    }

    int count = 0;
    int topoOrder[MAX];

    while (top != -1) {
        int u = pop();
        topoOrder[count++] = u;

        // For each vertex v adjacent to u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    push(v);
                }
            }
        }
    }

    if (count != n) {
        printf("Graph has a cycle; topological sorting not possible.\n");
        return;
    }

    printf("Topological order:\n");
    for (int i = 0; i < count; i++)
        printf("%d ", topoOrder[i]);
    printf("\n");
}

int main() {
    int e, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination), 0-indexed:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    topologicalSort();

    return 0;
}
