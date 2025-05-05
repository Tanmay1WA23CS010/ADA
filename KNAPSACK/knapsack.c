#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100

int main() {
    int n, W;
    int weight[MAX_ITEMS], profit[MAX_ITEMS];
    int V[MAX_ITEMS + 1][MAX_CAPACITY + 1];
    int items_included[MAX_ITEMS];

    // Input number of items and maximum capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Input the weights and profits
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    // Initialize the V array (Dynamic Programming table)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                V[i][j] = 0; // Base case
            else if (weight[i - 1] <= j)
                V[i][j] = (V[i - 1][j - weight[i - 1]] + profit[i - 1] > V[i - 1][j]) 
                            ? V[i - 1][j - weight[i - 1]] + profit[i - 1] 
                            : V[i - 1][j];
            else
                V[i][j] = V[i - 1][j];
        }
    }

    // Maximum profit is in V[n][W]
    printf("Maximum profit is: %d\n", V[n][W]);

    // Trace back to find the items included in the optimal solution
    int remaining_capacity = W;
    int item_count = 0;

    for (int i = n; i > 0; i--) {
        if (V[i][remaining_capacity] != V[i - 1][remaining_capacity]) {
            items_included[item_count++] = i; // Item i is included
            remaining_capacity -= weight[i - 1]; // Update remaining capacity
        }
    }

    // Output the items included in the optimal solution
    printf("Items included in the optimal solution (1-indexed): ");
    for (int i = item_count - 1; i >= 0; i--) {
        printf("%d ", items_included[i]);
    }
    printf("\n");

    return 0;
}
