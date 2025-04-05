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
    int middle = lbound + (rbound - lbound) / 2;
    if (arr[middle] == value) {
      while (arr[middle - 1] == arr[middle]) {
        middle--;
      }
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
  int temp = index;
  if (index == -1) {
    return 0;
  }
  while (arr[temp] == arr[temp + 1]) {
    count++;
    temp++;
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
