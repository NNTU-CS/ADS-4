// Copyright 2021 NNTU-CS
#include <iostream>
int countPairs1(int *arr, int len, int value) {
  int pairCount = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        pairCount++;
      }
    }
  }
  return pairCount;
}
int countPairs2(int *arr, int len, int value) {
  int pairCount = 0;
  int rightLimit = len - 1;
  while (rightLimit > 0 && arr[rightLimit] > value) {
    rightLimit--;
  }
  for (int leftIndex = 0; leftIndex < len; leftIndex++) {
    for (int rightIndex = rightLimit; rightIndex > leftIndex; rightIndex--) {
      if (arr[leftIndex] + arr[rightIndex] == value) {
        pairCount++;
      }
    }
  }
  return pairCount;
}
int binarySearchCount(int *arr, int left, int right, int target) {
  int firstIndex = -1;
  int lastIndex = -1;
  int low = left;
  int high = right;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target) {
      if (arr[mid] == target) {
        firstIndex = mid;
      }
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (firstIndex == -1) {
    return 0;
  }
  low = firstIndex;
  high = right;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) {
      if (arr[mid] == target) {
        lastIndex = mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return (lastIndex - firstIndex) + 1;
}
int countPairs3(int *arr, int len, int value) {
  int pairCount = 0;
  for (int index = 0; index < len; index++) {
    pairCount += binarySearchCount(arr, index + 1, len - 1, value - arr[index]);
  }
  return pairCount;
}
