// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = len - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int middle = len / 2;
  if (middle * 2 != len){
    int lMiddle = middle;
    int rMiddle = middle + 1;
    for (int i = 0; i < lMiddle; i++) {
      for (int j = i + 1; j < lMiddle; j++) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
    for (int i = len - 1; i >= rMiddle; i--) {
      for (int j = i - 1; j >= rMiddle; j--) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  } else {
    for (int i = 0; i < middle; i++) {
      for (int j = i + 1; j < middle; j++) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
    for (int i = len - 1; i >= middle; i--) {
      for (int j = i - 1; j >= middle; j--) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  }
  return count;
}
