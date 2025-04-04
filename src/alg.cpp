// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
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
            int left_count = 0;
            while (arr[left] == left_val) {
                left++;
                left_count++;
            }
            int right_val = arr[right];
            int right_count = 0;
            while (arr[right] == right_val) {
                right--;
                right_count++;
            }
            count += left_count * right_count;
        }
        else if (sum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return count;
}
int countDuplicates(int *arr, int len, int index, int target) {
    int count = 0;
    int left = index;
    while (left >= 0 && arr[left] == target) {
        count++;
        left--;
    }
    int right = index + 1;
    while (right < len && arr[right] == target) {
        count++;
        right++;
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) {
            continue;
        }
        int target = value - arr[i];
        int low = i + 1;
        int high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                count += countDuplicates(arr, len, mid, target);
                break;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return count;
}
