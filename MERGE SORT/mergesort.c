#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int low, int high);

int main() {
    int a[15000], n, ch;
    clock_t start, end;

    while (1) {
        printf("\n1: Manual entry of array elements");
        printf("\n2: Time taken for sorting N in range 500 to 14500");
        printf("\n3: Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);
                printf("Enter array elements: ");
                for (int i = 0; i < n; i++) scanf("%d", &a[i]);
                start = clock();
                mergeSort(a, 0, n - 1);
                end = clock();
                printf("\nSorted array: ");
                for (int i = 0; i < n; i++) printf("%d\t", a[i]);
                printf("\nTime taken: %.6f sec", (double)(end - start) / CLOCKS_PER_SEC);
                break;

            case 2:
                for (n = 500; n <= 14500; n += 1000) {
                    for (int i = 0; i < n; i++) a[i] = n - i;  // Reverse array
                    start = clock();
                    mergeSort(a, 0, n - 1);
                    end = clock();
                    printf("\nTime taken to sort %d elements: %.6f sec", n, (double)(end - start) / CLOCKS_PER_SEC);
                }
                break;

            case 3: exit(0);
            default: printf("\nInvalid choice.");
        }
    }
    return 0;
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int temp[15000], i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= high) temp[k++] = a[j++];
    for (i = low; i <= high; i++) a[i] = temp[i];
}