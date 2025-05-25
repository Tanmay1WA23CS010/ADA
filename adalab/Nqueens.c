#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Max board size you want to support

int x[MAX];  // Global array for queen positions (1-based indexing)

// Check if queen can be placed at row k, column i
int Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;  // Conflict found
    }
    return 1;  // Safe to place
}

// Recursive function to solve N-Queens
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int row = 1; row <= n; row++)
                    printf("%d ", x[row]);
                printf("\n");
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("N is too large. Max allowed is %d\n", MAX);
        return 1;
    }

    printf("Solutions for %d-Queens problem:\n", n);
    NQueens(1, n);

    return 0;
}
