// Copyright 2021 NNTU-CS
#include <iostream>
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
  int count = 0;
  std::sort(arr, arr + len);
  int left = 0;
  int right = len - 1;
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
  return 0;
}
int binarySearch(int* arr, int el, int left, int right) {
  int count = 0;
  int mid = 0;
  temp = 0;
  bool flag = false;
  int i;
  i = left - 1;
  while ((left <= right) && (flag != true)) {
      mid = (left + right) / 2;
      if (arr[mid] == el) {
          flag = true;
          temp = mid;
          count++;
      }
      if (arr[mid] > el) {
          right = mid - 1;
      } else {
          left = mid + 1;
      }
  }
  while (arr[mid] == el) {
      mid++;
      if (arr[mid] == el) count++;
  }
  mid = temp - 1;
  while ((arr[mid] == el) && (mid > i)) {
      if (arr[mid] == el) count++;
      mid--;
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0, i = 0, el;
  while (i < len) {
      el = value - arr[i];
      count += binarySearch(arr, el, i + 1, len - 1);
      i++;
  }
  return count;
}
