#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int findKthLargest(int nums[], int size, int k) {
    qsort(nums, size, sizeof(int), compare);
    return nums[size - k];
}

int main() {
    int nums[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    printf("%dth largest element is %d\n", k, findKthLargest(nums, sizeof(nums)/sizeof(nums[0]), k));
    return 0;
}


