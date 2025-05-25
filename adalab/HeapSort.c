#include <stdio.h>
#include <time.h>

// Swap elements at indices x and y in array arr
void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

// Heapify subtree rooted at index i in arr[] of size n
void heapify(int arr[], int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;       // left child index
    int right = 2 * i + 2;      // right child index

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr, 0, i);     // Move current root to end
        heapify(arr, i, 0);  // Heapify reduced heap
    }
}

// Utility to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    return 0;
}
