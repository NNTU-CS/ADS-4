// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int co = 0;
  for (int x = 0; x < len; ++x) {
    for (int m = x + 1; m < len; ++m) {
      if (arr[x] = value - arr[m] && x != m) {
        co += 1;
      }
    }
  }
  return 0;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
int m = len - 1;
int x = 0;
int count2 = 0;
int musor1 = 0;
while (x < m) {
  if (arr[x] + arr[m] == value) {
    ++count2;
    ++musor1;
    --m;
  } else {
    if (musor1) {
      ++x;
      m += musor1;
      musor1 = 0;
    }
    if (arr[x] + arr[m] > value) {
      --m;
    } else if (arr[x] + arr[m] < value) {
      ++x;
    }
  }
}
return count2;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
}
