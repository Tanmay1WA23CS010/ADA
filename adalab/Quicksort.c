#include <stdio.h>

// Swap elements at indices x and y in array arr (no pointers)
void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

// Partition function using only while loops
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1;

    while (1) {
        // Move i right while arr[i] <= pivot and i < high
        while (i < high && arr[i + 1] <= pivot) {
            i++;
        }
        i++; // Advance once more to match behavior

        // Move j left while arr[j] > pivot and j > low
        while (j > low && arr[j - 1] > pivot) {
            j--;
        }
        j--; // Adjust after loop to point to first valid

        if (i >= j)
            break;

        swap(arr, i, j);
    }

    swap(arr, low, j);
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
