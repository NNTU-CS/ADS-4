// Copyright 2021 NNTU-CS
#include <iostream>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
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
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int num = right - left + 1;
        count += num * (num - 1) / 2;
        break;
      } else {
        int cntLeft = 1, cntRight = 1;
        while (left + cntLeft < right && arr[left + cntLeft] == arr[left]) cntLeft++;
        while (right - cntRight > left && arr[right - cntRight] == arr[right]) cntRight++;
        count += cntLeft * cntRight;
        left += cntLeft;
        right -= cntRight;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int countOccurrences(int *arr, int left, int right, int target) {
  int low = left, high = right, mid;
  int first = -1, last = -1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      first = mid;
      high = mid - 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (first == -1)
    return 0;
  low = first, high = right;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      last = mid;
      low = mid + 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return last - first + 1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    count += countOccurrences(arr, i + 1, len - 1, value - arr[i]);
  }
  return count;
}
