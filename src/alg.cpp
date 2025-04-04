// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <vector>

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
      int left_val = arr[left];
      int right_val = arr[right];
      int left_count = 1;
      int right_count = 1;

      while (left < right && arr[left + 1] == left_val) {
        left++;
        left_count++;
      }
      while (left < right && arr[right - 1] == right_val) {
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
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int duplicate_count = 1;
        int j = mid + 1;
        while (j < len && arr[j] == target) {
          duplicate_count++;
          j++;
        }
        count += duplicate_count;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
