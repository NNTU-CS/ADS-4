// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) ++count;
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int temp = len;
  while (arr[len - 1] > value) --len;
  for (int i = 0; i < temp; ++i) {
    for (int j = len - 1; j > i; --j) {
      if (arr[i] + arr[j] < value) break;
      if (arr[i] + arr[j] == value) ++count;
    }
  }
  return count;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int lbound = i + 1, rbound = len - 1, target = value - arr[i];
    while (lbound <= rbound) {
      int mid = lbound + (rbound - lbound) / 2;
      if (arr[mid] == target) {
        ++count;
        int current = mid;
        while (++current <= rbound && arr[current] == target) ++count;
        current = mid;
        while (--current >= lbound && arr[current] == target) ++count;
        break;
      }
      if (arr[mid] > target) rbound = mid - 1;
      if (arr[mid] < target) lbound = mid + 1;
    }
  }
  return count;
}
