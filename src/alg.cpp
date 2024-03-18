// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
  int k1 = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i+1; j < len; j++) {
          if (arr[i] + arr[j] == value) {
              k1++;
          }
      }
  }
  return k1;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  int k2 = 0;
  for (int i = 0; i < len - 1; i++) {
      for (int j = 0; j < len - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
              int temp = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
          }
      }
  }
  for (int i = 0; i < len; i++) {
    int left = i + 1;
    int right = len - 1;
    while (left < right) {
        int summ = arr[i] + arr[left] + arr[right];
            if (summ == value) {
                k2++;
                left++;
                right--;
            } else if (summ < value) {
                left++;
            } else {
                right--;
            }
    }
  }
  return k2;
  return 0;
}
int cbinsearch(int *arr, int size, int value) {
  int counter = 0;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == value) {
          counter++;
          int i = mid + 1;
          while (i < size && arr[i] == value) {
              counter++;
              i++;
          }
          i = mid - 1;
          while (i >= 0 && arr[i] == value) {
              counter++;
              i--;
          }
          return counter;
      } else if (arr[mid] < value) {
          left = mid + 1;
      } else {
          right = mid - 1;
      }
  }
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int k3 = 0;
  int i = 0;
  while (i < len) {
      int numbers = value - arr[i];
      k3 = k3 + cbinsearch(&arr[i + 1], len - i - 1, numbers);
      i++;
  }
  return k3;
  return 0;
}
