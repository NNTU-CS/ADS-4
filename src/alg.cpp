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
    int right = len;
    int left = i;
    while (left < right - 1) {
      int middle = (left + right) / 2;
      if (arr[i] + arr[middle] == value) {
        cnt++;
        int j = middle + 1;
        while ((arr[i] + arr[j] == value) && (j < right)) {
          cnt++;
          j++;
        }
      }
      if (arr[i] + arr[middle] < value) {
        left = middle;
      } else {
        right = middle;
      }
    }
  }
  return cnt;
}
