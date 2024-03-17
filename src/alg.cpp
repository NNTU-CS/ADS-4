// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>


int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count = count + 1;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count = count + 1;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int leftInd = i;
    int rightInd = len;
    while (leftInd < rightInd-1) {
      int middle = (leftInd + rightInd) / 2;
      if (arr[i] + arr[middle] == value) {
        count = count + 1;
        int j = middle+1;
        while (arr[i] + arr[j] == value && j < rightInd) {
          count = count + 1;
          j = j+1;
        }
        j = middle - 1;
        while (arr[i] + arr[j] == value && j > leftInd) {
          count = count + 1;
          j = j - 1;
        }
      break;
      }
      if (arr[i] + arr[middle] > value) {
        rightInd = middle;
      } else {
        leftInd = middle;
      }
    }
  }
  return count;
}
