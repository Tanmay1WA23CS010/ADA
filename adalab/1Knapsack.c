#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int weight[], int value[], int n, int capacity) {
    int v[MAX][MAX]; // v[i][j]: max value with first i items and capacity j

    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (weight[i] <= j) {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + value[i]);
            } else {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    printf("Maximum profit: %d\n", v[n][capacity]);

    // Trace back the selected items
    printf("Items included:\n");
    int i = n, j = capacity;
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i - 1][j]) {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weight[i], value[i]);
            j -= weight[i];
        }
        i--;
    }
}

int main() {
    int n, capacity;
    int weight[MAX], value[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and values of the items:\n");
    for (int i = 1; i <= n; i++) {
        printf("Weight of item %d: ", i);
        scanf("%d", &weight[i]);
        printf("Value of item %d: ", i);
        scanf("%d", &value[i]);
    }

    printf("Enter capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(weight, value, n, capacity);
    return 0;
}
