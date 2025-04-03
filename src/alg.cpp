// Copyright 2021 NNTU-CS
#include <iostream>
#include <array>
#include <algorithm>

// cppcheck-suppress constParameterPointer
int countPairs1(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        kol++;
      }
    }
  }
  return kol;
}

// cppcheck-suppress constParameterPointer
int countPairs2(int* arr, int len, int value) {
  int kol = 0;
  int end = len - 1;
  while (end > 0) {
    if (arr[end] > value) {
      end--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = end; j > i; j--) {
      if (arr[i] + arr[j] == value)
        kol++;
    }
  }
  return kol;
}

// cppcheck-suppress constParameterPointer
int binar_poisk(int *arr, int low, int high, int value) {
  int first = -1;
  int left = low, right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= value) {
      right = mid - 1;
      if (arr[mid] == value) first = mid;
    } else {
    left = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  left = first;
  right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= value) {
      left = mid + 1;
      if (arr[mid] == value) last = mid;
    } else {
      right = mid - 1;
    }
  }
  return last - first + 1;
}

// cppcheck-suppress constParameterPointer
int countPairs3(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; ++i) {
    kol += binar_poisk(arr, i + 1, len - 1, value - arr[i]);
  }
  return kol;
}
