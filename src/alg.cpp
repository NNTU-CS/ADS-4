// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  return 0;
  int count = 0;
  for (int k = 0; k < len; ++k) {
    for (int r = k + 1; r < len; ++r) {
      if (arr[k] + arr[r] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
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
  return 0;
  int count = 0;
  for (int k = 0; k < len; ++k) {
    int required = value - arr[k];
    int *pos = std::lower_bound(arr + k + 1, arr + len, required);
    if (pos != arr + len && *pos == required) {
      count++;
    }
  }
  return count;
}
