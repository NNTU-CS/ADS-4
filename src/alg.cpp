// Copyright 2021 NNTU-CS
#include <iostream>
#include <array>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  int kol = 0;
  int ind = 0;
  while (ind < len - 1) {
    int inn = ind + 1;
    while (inn < len) {
      int sum = arr[ind] + arr[inn];
      if (sum == value) {
        kol++;
        while (inn < len - 1 && arr[inn] == arr[inn + 1]) {
          inn++;
        }
        break;
      }
      if (sum > value) break;
      inn++;
    }
    while (ind < len - 1 && arr[ind] == arr[ind + 1]) {
      ind++;
    }
    ind++;
  }
  return kol;
}

int countPairs2(int *arr, int len, int value) {
  int kol = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      kol++;
      while (left < right && arr[left] == arr[left + 1]) left++;
      while (left < right && arr[right] == arr[right - 1]) right--;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return kol;
}

int binar_poisk(int *arr, int nach, int end, int sdv) {
  int low = nach;
  int iind = end;
  while (low <= iind) {
    int mid = (low + iind) >> 1;
    int value = arr[mid];
    if (value == sdv) return mid;
    if (value < sdv) low = mid + 1;
    else iind = mid - 1;
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
    int kol = 0;
    int position = 0;
    while (position < len - 1) {
        int complement = value - arr[position];
        if (complement < 0) {
            position++;
            continue;
        }
        int match = binar_poisk(arr, position + 1, len - 1, complement);
        if (match != -1) {
            kol++;
            while (match < len - 1 && arr[match] == arr[match + 1]) {
                match++;
            }
        }
        int current = arr[position];
        while (position < len - 1 && arr[position] == current) {
            position++;
        }
        position++;
    }
    return kol;
}
