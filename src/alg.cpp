// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] > value) continue;
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
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
            if (arr[left] != arr[right]) {
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
            } else {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
inline int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            while (mid > left && arr[mid - 1] == target) mid--;
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (arr[i] > value) break;
        int complement = value - arr[i];
        if (complement < arr[i]) continue;
        int j = binarySearch(arr, i + 1, len - 1, complement);
        if (j != -1) {
            while (j < len && arr[j] == complement) {
                count++;
                j++;
            }
        }
    }
    return count;
}
