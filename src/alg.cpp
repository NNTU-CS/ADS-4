// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
#include <alg.h>
#include <iostream>
#include <cstdint>
using namespace std;
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
    }
  }
  if (count > (0)) {
    return count;
  }
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
int countPairs2(int* arr, int len, int value) {
  int count = 0, x = 0, j = 0;
  for (int i = 0; i < (len - 1); i++) {
    if ((arr[i] + arr[i + 1]) >= value) {
      x = i;
      break;
    }
  }
  for (int i = 0; i < (len - 1); i++) {
    if (arr[i] > value) {
      break;
    }
    if (x <= i) {
      j = i + 1;
    } else {
      j = x;
    }
    for (; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
      if (arr[j] > value) {
        break;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
int countPairs3(int* arr, int len, int value) {
  int count = 0, y = 0, min = 0, max = len;
  for (int i = 0; i < (len - 1); i++) {
    if (arr[i] > value) {
      break;
    }
    min = i;
    max = len - 1;
    while (min < max) {
      y = min + ((max - min) / 2);
      if (min == max) {
        break;
      }
      if ((arr[i] + arr[y]) > value) {
        for (int n = (y - 1); n >= min; n--) {
          max = n + 1;
          if (arr[y] != arr[n]) {
            break;
          }
        }
        if (max - min == 1) {
          break;
        }
      }
      if ((arr[i] + arr[y]) < value) {
        for (int n = (y + 1); n <= max; n++) {
          min = n - 1;
          if (arr[y] != arr[n]) {
            break;
          }
        }
        if (max - min== 1) {
          break;
        }
      }
      if ((arr[i] + arr[y]) == value) {
        int t = max;
        for (int n = (y + 1); n <= t; n++) {
          max = n - 1;
          if (arr[y] != arr[n]) {
            break;
          }
        }
        t = min;
        for (int n = (y - 1); n >= t; n--) {
          min = n + 1;
          if (arr[y] != arr[n]) {
            break;
          }
        }
        break;
      }
    }
    for (int j = min; j <= max; j++) {
      if (((arr[i] + arr[j]) == value) && (i != j)) {
        count++;
      }
    }
  }
  return count;
}
