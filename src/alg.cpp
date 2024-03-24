// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int k = 0; k < len; ++k) {
    for (int r = r + 1; r < len; ++r) {
      if (arr[k] + arr[r] == value) {
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
    if (arr[left] + arr[right] == value) {
      count++;
      left++;
      right--;
    } else if (arr[left] + arr[right] < value) {
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
    int required = value - arr[i];
    int *pos = std::lower_bound(arr + i + 1, arr + len, required);
    if (pos != arr + len && *pos == required) {
      count++;
    }
  }
  return count;
}

int main() {
    int arr[] = {20, 30, 30, 40, 40};
    int len = sizeof(arr) / sizeof(arr[0]);
    int value = 50;
