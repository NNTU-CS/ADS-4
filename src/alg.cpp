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
int countPairs3(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; ++i) {
        int cel = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == cel) {
                kol++;
                int j = mid - 1;
                while (j >= left && arr[j] == cel) {
                    kol++;
                    j--;
                }
                j = mid + 1;
                while (j <= right && arr[j] == cel) {
                    kol++;
                    j++;
                }
                break;
            } else if (arr[mid] < cel) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return kol;
}
