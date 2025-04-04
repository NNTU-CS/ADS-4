// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
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
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 1;
            int right_count = 1;
            
            while (left + 1 < right && arr[left + 1] == left_val) {
                left++;
                left_count++;
            }
            while (right - 1 > left && arr[right - 1] == right_val) {
                right--;
                right_count++;
            }
            count += left_count * right_count;
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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        if (target < arr[i]) break;
        int* lower = std::lower_bound(arr + i + 1, arr + len, target);
        if (lower != arr + len && *lower == target) {
            int* upper = std::upper_bound(arr + i + 1, arr + len, target);
            count += upper - lower;
        }
    }
    return count;
}
