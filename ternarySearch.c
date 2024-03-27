#include <stdio.h>

// Function to perform Ternary Search
int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Check if key is present at mid1 or mid2
        if (arr[mid1] == key)
            return mid1;
        if (arr[mid2] == key)
            return mid2;

        // If key is smaller than mid1, search in the left one-third
        if (key < arr[mid1])
            return ternarySearch(arr, left, mid1 - 1, key);
        // If key is larger than mid2, search in the right one-third
        else if (key > arr[mid2])
            return ternarySearch(arr, mid2 + 1, right, key);
        // If key is between mid1 and mid2, search in the middle one-third
        else
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
    
    // Key not found
    return -1;
}

// Main function to demonstrate Ternary Search
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform ternary search
    int result = ternarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element %d is not present in the array\n", key);
    else
        printf("Element %d is present at index %d\n", key, result);

    return 0;
}
