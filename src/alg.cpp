// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(const int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(const int *arr, int len, int value) {
  int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(const int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if (std::binary_search(arr + i + 1, arr + len, complement)) {
            count++;
        }
    }
    return count;
}
