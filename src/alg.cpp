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
    for (int j = len - 1; j > len; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
      if (value - arr[i] > arr[j]) {
        break;
      }
    }
  }
  return count; }
int countPairs3(int *arr, int len, int value) { return 0; }
