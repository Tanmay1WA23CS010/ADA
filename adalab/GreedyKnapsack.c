#include <stdio.h>

#define MAX 20

float weight[MAX], profit[MAX], ratio[MAX];
int n;

// Corrected swap function: accepts array and indexes
void swap(float arr[], int i, int j) {
    float temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sortByRatio() {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(profit, i, j);
                swap(weight, i, j);
                swap(ratio, i, j);
            }
        }
    }
}

void fractionalKnapsack(float capacity) {
    float totalProfit = 0;
    float x[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            x[i] = 1;
            totalProfit += profit[i];
            capacity -= weight[i];
        } else {
            x[i] = capacity / weight[i];
            totalProfit += profit[i] * x[i];
            break;
        }
    }

    printf("\nFractions of items taken:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }
    printf("Maximum profit: %.2f\n", totalProfit);
}

int main() {
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights and profits of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%f", &weight[i]);
        printf("Profit of item %d: ", i + 1);
        scanf("%f", &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    sortByRatio();
    fractionalKnapsack(capacity);

    return 0;
}
