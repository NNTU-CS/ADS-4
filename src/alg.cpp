// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        k++;
      }
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int r = len - 1;
  while (arr[r] > value) {
    r--;
  }
  int k = 0;
  for (int i = 0; i < r; i++) {
    for (int j = r; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        k++;
      } else if (arr[i] + arr[j] < value) {
        break;
        }
    }
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  int left;
  int right, mid, sredn;
  for (int i = 0; i < len; ++i) {
    right = len - 1;
    left = i + 1;
    sredn = value - arr[i];
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid] == sredn) {
        k++;
        int p = mid - 1;
        while ((p > i) && (arr[p] == arr[mid])) {
          k++;
          p--;
        }
        int p2 = mid + 1;
        while ((i < p2) && (arr[p2] == arr[mid])) {
          k++;
          p2++;
        }
        break;
        } else if (arr[mid] > sredn) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
    }
  }
  return k;
}
