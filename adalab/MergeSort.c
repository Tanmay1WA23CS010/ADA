#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void split(int[], int, int);
void combine(int[], int, int, int);

int main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;  // For timing the sort

    while (1) {
        // Display menu
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            // Manual array input
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter array elements:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            // Start timing
            start = clock();
            split(a, 0, n - 1);  // Perform merge sort
            end = clock();

            // Display sorted array
            printf("\nSorted array is:\n");
            for (i = 0; i < n; i++)
                printf("%d\t", a[i]);

            // Show time taken
            printf("\nTime taken to sort %d numbers is %f seconds\n",
                   n, ((double)(end - start)) / CLOCKS_PER_SEC);
            break;

        case 2:
            // Run automatic test for increasing N values
            n = 500;
            while (n <= 14500) {
                // Fill array in reverse order (worst case)
                for (i = 0; i < n; i++) {
                    a[i] = n - i;
                }

                start = clock();
                split(a, 0, n - 1);
               
                end = clock();

                printf("Time taken to sort %d numbers is %f seconds\n",
                       n, ((double)(end - start)) / CLOCKS_PER_SEC);

                n += 1000;
            }
            break;

        case 3:
            exit(0);  // Exit the program

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Recursive function to divide array into halves
void split(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        split(a, low, mid);       // Left half
        split(a, mid + 1, high);  // Right half
        combine(a, low, mid, high);  // Merge sorted halves
    }
}

// Function to merge two sorted halves
void combine(int a[], int low, int mid, int high) {
    int c[15000];  // Temporary array for merging
    int i = low, j = mid + 1, k = low;

    // Compare elements of both halves and copy the smaller one
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];  // If left is smaller
        } else {
            c[k++] = a[j++];  // If right is smaller
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        c[k++] = a[i++];
    }

    // Copy remaining elements from right half
    while (j <= high) {
        c[k++] = a[j++];
    }

    // Copy merged result back into original array
    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
