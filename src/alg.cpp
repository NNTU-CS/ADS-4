// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] = value - arr[j] && i != j) {
        count += 1;
      }
    }
  }
  return 0;
}

int countPairs2(int *arr, int len, int value) {
int j = len - 1;
int i = 0;
int count = 0;
int musor = 0;
while (i < j) {
  if (arr[i] + arr[j] == value) {
    ++count;
    ++musor;
    --j;
  } else {
    if (musor) {
      ++i;
      j += musor;
      musor = 0;
    }
    if (arr[i] + arr[j] > value) {
      --j;
    } else if (arr[i] + arr[j] < value) {
      ++i;
    }
  }
}
return count;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
}
