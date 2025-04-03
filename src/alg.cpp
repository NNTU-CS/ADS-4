// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

// cppcheck-suppress constParameterPointer
int countPairs1(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                kol++;
            }
        }
    }
    return kol;
}

// cppcheck-suppress constParameterPointer
int countPairs2(int *arr, int len, int value) {
    int kol = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                kol += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left];
                int right_val = arr[right];
                int left_kol = 0;
                int right_kol = 0;
                while (left < len && arr[left] == left_val) {
                    left++;
                    left_kol++;
                }
                while (right >= 0 && arr[right] == right_val) {
                    right--;
                    right_kol++;
                }
                kol += left_kol * right_kol;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return kol;
}

// cppcheck-suppress constParameterPointer
int Binar_poisk(int *arr, int low, int high, int value) {
  int first = -1;
  int left = wit, right = high;
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

int countPairs3(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; ++i) {
    kol += Binar_poisk(arr, i + 1, len - 1, value - arr[i]);
  }
  return kol;
}
