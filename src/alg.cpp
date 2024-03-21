// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cnt++;
      }
    }
  }
  return cnt;
}
}
int countPairs2(int *arr, int len, int value) {
  int k = len - 1;
  int cnt = 0;
  for (int i = len-1; i > 0; --i) {
    if (arr[i] > value) {
      k = i;
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = len - 1; j > k; --j) {
      if (arr[i] + arr[j] == value) {
        cnt++;
      }
    }
  }
  return cnt;
}
int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
    for (int i = 0; i < len - 1; i++) {
      int left = i + 1, right = len - 1;
      while (left <= right) {
        int sum = arr[i] + arr[right];
        if (sum == value) {
          cnt++;
          int j = right - 1;
          while (arr[i] + arr[j] == value) {
            cnt++;
            j--;
          }
        break;
        } else if (sum > value) {
          right--;
        } else {
          left++;
        }
      }
    }
    return cnt;
}
