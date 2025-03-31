// Copyright 2021 NNTU-CS
#include <iostream>
#include <time.h>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)count++;
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int els = 0;
  int index = len - 1;
  while (index > 0) {
    if (arr[index] > value) {
      index--;
    } else {
      break;
    }
  }
  int i = 0;
  while (i < len) {
    int j = index;
    while (j > i) {
      if (arr[i] + arr[j] == value) els++;
      j--;
    }
    i++;
  }
  return els;
}

int findFirstOccurrence(int* arr, int low, int high, int value) {
  int first = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= value) {
      high = mid - 1;
      if (arr[mid] == value) {
        first = mid;
      }
    } else {
      low = mid + 1;
    }
  }
  return first;
}


int findLastOccurrence(int* arr, int low, int high, int value) {
  int last = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= value) {
      low = mid + 1;
      if (arr[mid] == value) {
        last = mid;
      }
    } else {
      high = mid - 1;
    }
  }
  return last;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int last = findLastOccurrence(arr, i + 1, len - 1, value - arr[i]);
    int first = findFirstOccurrence(arr, i + 1, len - 1, value - arr[i]);
    if (last != -1 || first != -1) count += last - first + 1;
  }
  return count;
}

