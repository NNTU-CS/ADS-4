// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count; }
int countPairs2(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len/2; i++) {
    for (int j = len - 1; j > 0; j--) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
      if ((value - arr[i]) > arr[j]) {
        break;
      }
    }
  }
  return count; }
int countPairs3(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len; i++) {
    int left_bound = 0;
    int right_bound = len-1;
    while (left_bound < right_bound) {
      int middle = (left_bound + right_bound) / 2;
      if (arr[middle] == (value - arr[i])) {
        count++;
        bool flag = 1;
        int left = middle - 1, right = middle + 1;
        while (flag) {
          if (arr[left] == arr[middle] &&
              arr[right] != arr[middle]) {
            count++;
            left--;
            continue;
          }
          if (arr[left] != arr[middle] && arr[right] == arr[middle]) {
            count++;
            right++;
            continue;
          }
          if (arr[left] == arr[middle] && arr[right] == arr[middle]) {
            count += 2;
            left--;
            right++;
            continue;
          }
          if (arr[left] != arr[middle] && arr[right] != arr[middle]) {
            left_bound = right_bound + 5;
            flag = 0;
          }
        }
      }
      if ((arr[middle]) < (value - arr[i])) {
        left_bound = middle + 1;
      }
      if ((arr[middle]) > (value - arr[i])) {
        right_bound = middle - 1;
      }
    }
  }
  return count/2; }
