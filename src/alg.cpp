// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

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
  int count = 0;
  int right, m1, m2, left;
  for (int i = 0; i < len; ++i) {
    right = len - 1;
    left = i + 1;
    m2 = value - arr[i];
    while (left <= right) {
      mid1 = (left + right) / 2;
      if (arr[m1] == m2) {
        count++;
        int next = m1 - 1;
        while ((next > i) && (arr[next] == arr[m1])) {
          count++;
          next--;
        }
        int next2 = m1 + 1;
        while ((i < next2) && (arr[next2] == arr[m1])) {
          count++;
          next2++;
        }
        break;
      } else if (arr[m1] > m2) {
        right = m1 - 1;
      } else {
        left = m1 + 1;
      }
    }
  }
  return count;
}
