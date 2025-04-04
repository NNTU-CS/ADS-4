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
      int lVal = arr[left];
      int rVal = arr[right];
      int lCount = 0;
      int rCount = 0;

      if (lVal == rVal) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }

      while (left <= right && arr[left] == lVal) {
        lCount++;
        left++;
      }

      while (right >= left && arr[right] == rVal) {
        rCount++;
        right--;
      }

      count += lCount * rCount;
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
    int complement = value - arr[i];

    int left = std::lower_bound(arr + i + 1, arr + len, complement) - arr;
    int right = std::upper_bound(arr + i + 1, arr + len, complement) - arr;

    count += (right - left);
  }

  return count;
}
