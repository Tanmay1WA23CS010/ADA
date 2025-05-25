#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

// Function to print a permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to find the largest mobile integer
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[i];
        if (next >= 0 && next < n && perm[i] > perm[next]) {
            if (perm[i] > mobile)
                mobile = perm[i];
        }
    }
    return mobile;
}

// Function to get the index of a value in the array
int getIndex(int perm[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == val)
            return i;
    }
    return -1;
}

// Function to generate all permutations using Johnson-Trotter
void johnsonTrotter(int perm[], int n) {
    int dir[n];

    // Initialize directions to LEFT
    for (int i = 0; i < n; i++) {
        dir[i] = LEFT;
    }

    printPermutation(perm, n);  // print initial permutation

    while (1) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == 0)
            break;

        int pos = getIndex(perm, n, mobile);
        int next = pos + dir[pos];

        // Swap elements and their directions
        swap(perm, pos, next);
        swap(dir, pos, next);

        // Reverse direction of all elements greater than the current mobile
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[i] = -dir[i];
        }

        printPermutation(perm, n);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int perm[n];
    printf("Enter %d distinct elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
    }

    printf("All permutations using Johnson-Trotter:\n");
    johnsonTrotter(perm, n);

    return 0;
}
