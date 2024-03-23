// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  sort(arr, arr+len);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int bi(int* arr, int len, int value) {
  if (len == 0) return 0;
  if (arr[len / 2] == value) return value;
  if (arr[len / 2] > value) return bi(arr, len / 2, value);
  return 0;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int i =  len - 1;
  while (arr[i] > value) {
    i--;
  }
  len = i + 1;
  count += countPairs1(arr, len, value);
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int j = 0;
  int count = 0;
  while (arr[j] <= (value / 2) - 1) {
    int b = value - arr[j];
    count += bi(arr, len, b);
    j++;
  }
  int n = bi(arr, len, value / 2);
  count += n * (n - 1) / 2;
  return count;
}
