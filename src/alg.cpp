// Copyright 2021 NNTU-CS

#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < len; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0, left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            do { left++; } while (left < right && arr[left] == arr[left - 1]);
            do { right--; } while (left < right && arr[right] == arr[right + 1]);
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int complement = value - arr[i];
        if (binarySearch(arr, i + 1, len - 1, complement) != -1) {
            count++;
        }
    }
    return count;
}
