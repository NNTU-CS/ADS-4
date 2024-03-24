#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

int countPairs1(int* arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                sum++;
            }
        }
    }
    return sum;
}

int countPairs2(int* arr, int len, int value) {
    int sum = 0;
    for (int j = len - 1; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            if (arr[j] + arr[i] == value) {
                sum++;
            }
        }
    }
    return sum;
}

int countPairs3(int* arr, int len, int value) {
    int sum = 0;
    std::sort(arr, arr + len); // Sort the array for binary search
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        // Binary search for the second value in the pair
        int low = i + 1, high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                sum++;
                break; // Break to avoid counting duplicates
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return sum;
}