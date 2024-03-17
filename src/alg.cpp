// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  int k = 0;
  while (k < len) {
    int i = k + 1;
    while (i < len) {
      if ((arr[k] + arr[i]) == value) {
        count++;
      }
      i++;
    }
    k++;
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int k = len - 1;
  do {
    k = k - 1;
  } 
  while (arr[k] > value);
    int i = 0;
    while (i < endl) {
      int j = endl;
        while (j > i) {
          if (arr[j] + arr[i] == value) {
            count++;
          }
          j--;
        }
        i++;
    }
    return count;
}
int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      count++;
    }
  }
  return count;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int k = 0;
  while (k < len) {
    int k1 = value - arr[k];
    count = count + cbinsearch(&arr[k + 1], len - k - 1, k1);
    k++;
  }
  return count;
}
