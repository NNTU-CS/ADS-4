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
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = len-1; j > i; --j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int left = i + 1, right = len - 1;
    while (left <= right) {
      int sum = arr[i] + arr[left];
      if (sum == value) {
        count++;
        break; 
      } 
      else if (sum < value) {
        left++;
      } 
      else {
        right--;
      }
    }
  } 
  return count;
}
