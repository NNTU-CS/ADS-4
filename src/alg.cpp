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
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
      if (arr[j] < (value - arr[i])) {
        break;
      }
    }
  }
  return count; }

int binarySearch_index(int *arr, int len, int value) { 
  int lbound = 0;
  int rbound = len - 1;
  while (rbound > lbound) {
    int middle = (lbound + rbound) / 2;
    if (arr[middle] == value) {
      return middle;
    }
    if (arr[middle] < value) {
      lbound = middle + 1;
    } else {
      rbound = middle - 1;
    }
  }
  return -1;
}

int binarySearch_count(int *arr, int len, int index ) { 
  int count = 1;
  if (index == -1) {
    return 0;
  }
  bool flag = 1;
  int left = index-1;
  int right = index + 1;
  while (flag) {
    if (arr[left] == arr[index] && left != -1) {
      count++;
      left--;
    }
    if (arr[right] == arr[index] && right != len) {
      count++;
      right++;
    }
    if (arr[left] != arr[index] && arr[right] != arr[index]) {
      break;
    }
  }
  return count;
  }

int countPairs3(int *arr, int len, int value) { 
  int count = 0;
  for (int i = 0; i < len; i++) {
    int* temp_arr = &arr[i];
    int temp_len = len - (i + 1);
    int find = value - arr[i];
    int index = binarySearch_index(temp_arr, temp_len, find);
    count += binarySearch_count(temp_arr, temp_len, index);
  }
  return count; }
