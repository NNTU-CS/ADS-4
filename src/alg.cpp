// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      if (arr[i] + arr[j] == value) ++count;
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
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
    int lbound = i, rbound = len - 1, target = value - arr[i];
    while (lbound < rbound) {
      if ((rbound - lbound) / 2 + lbound == target) {
        ++count;
        int current = (rbound - lbound) / 2 + lbound;
        while (true) {
          if (++current < rbound && arr[current] == target) ++count;
          else break;
        }
        current = (rbound - lbound) / 2 + lbound;
        while (true) {
          if (--current > lbound && arr[current] == target) ++count;
          else break;
        }
      }
      else if ((rbound - lbound) / 2 + lbound > target) rbound = (rbound - lbound) / 2 + lbound - 1;
      else lbound = (rbound - lbound) / 2 + lbound + 1;
    }
  }
  return count;
}
