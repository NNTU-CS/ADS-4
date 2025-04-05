// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value) k++;
  return k;
}

int countPairs2(int* arr, int len, int value) {
  int k = 0, r = len - 1, l = 0;
  while (r != l) {
    if (arr[r] + arr[l] > value) {
      r--;
    } else if (arr[r] + arr[l] == value) {
      r--;
      k++;
    } else if (arr[r] + arr[l] < value) {
      l++;
      r = len - 1;
    }
  }
  return k;
}

int countPairs3(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    int a = -1, l1 = i + 1, r1 = len - 1, v = value - arr[i];
    while (l1 <= r1) {
      int m = l1 + (r1 - l1) / 2;
      if (arr[m] >= v) {
        r1 = m - 1;
        if (arr[m] == v) a = m;
      } else {
        l1 = m + 1;
      }
    }
    if (a != -1) {
      int b = a;
      l1 = a;
      r1 = len - 1;
      while (l1 <= r1) {
        int m = l1 + (r1 - l1) / 2;
        if (arr[m] <= v) {
          l1 = m + 1;
          if (arr[m] == v) b = m;
        } else {
          r1 = m - 1;
        }
      }
      k += b - a + 1;
    }
  }
  return k;
}
