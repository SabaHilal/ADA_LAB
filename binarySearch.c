#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at the middle
        if (arr[mid] == key)
            return mid;

        // If the key is greater, ignore the left half
        if (arr[mid] < key)
            left = mid + 1;
        // If the key is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Key not found
    return -1;
}

// Main function to demonstrate Binary Search
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element %d is not present in the array\n", key);
    else
        printf("Element %d is present at index %d\n", key, result);

    return 0;
}
