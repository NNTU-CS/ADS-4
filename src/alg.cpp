// Copyright 2021 NNTU-CS
#include <iostream>
#include <array>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  const int *constArr = *arr;
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

int countPairs2(int *arr, int len, int value) {
  const int *constArr = *arr;
  int kol = 0;
  int right = len - 1;
  while (right > 0) {
    if (arr[right] > value) {
      right--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = right; j > i; j--) {
      if (arr[i] + arr[j] == value)
        kol++;
    }
  }
  return kol;
}

int Binar_poisk(int *arr, int low, int high, int value) {
  const int *constArr = *arr;
  int first = -1;
  int left = low, right = high;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] >= value) {
      right = middle - 1;
      if (arr[middle] == value) first = middle;
    } else {
    left = middle + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  left = first;
  right = high;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] <= value) {
      left = middle + 1;
      if (arr[middle] == value) last = middle;
    } else {
      right = middle - 1;
    }
  }
  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  const int *constArr = *arr;
  int kol = 0;
  for (int i = 0; i < len; ++i) {
    kol += Binar_poisk(arr, i + 1, len - 1, value - arr[i]);
  }
  return kol;
}
