// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

// cppcheck-suppress constParameterPointer
int countPairs1(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                kol++;
            }
        }
    }
    return kol;
}

// cppcheck-suppress constParameterPointer
int countPairs2(int *arr, int len, int value) {
    int kol = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                kol += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left];
                int right_val = arr[right];
                int left_kol = 0;
                int right_kol = 0;
                while (left < len && arr[left] == left_val) {
                    left++;
                    left_kol++;
                }
                while (right >= 0 && arr[right] == right_val) {
                    right--;
                    right_kol++;
                }
                kol += left_kol * right_kol;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return kol;
}

// cppcheck-suppress constParameterPointer
int countPairs(int *arr, int len, int value) {
    int kol = 0;
    std::sort(arr, arr + len);
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int leftIndex = i + 1;
        int right = len - 1;
        int first = -1;
        while (leftIndex <= right) {
            int mid = leftIndex + (right - leftIndex) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
                if (arr[mid] == target) first = mid;
            } else {
                leftIndex = mid + 1;
            }
        }
        if (first == -1) continue;
        int last = first;
        leftIndex = first;
        while (leftIndex <= right) {
            int mid = leftIndex + (right - leftIndex) / 2;
            if (arr[mid] <= target) {
                leftIndex = mid + 1;
                if (arr[mid] == target) last = mid;
            } else {
                right = mid - 1;
            }
        }
        kol += (last - first + 1);
    }
    return kol;
}
