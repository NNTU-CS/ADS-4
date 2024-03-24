// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cntr = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        cntr++;
      }
    }
  }
  return cntr;
}
int countPairs2(int *arr, int len, int value) {
  int cntr = 0;
  int t = len - 1;
  while (arr[t] > value) {
    t--;
  }
  for (int i = 0; i < len; i++) {
    for (int j = t; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        cntr++;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return cntr;
}
int countPairs3(int *arr, int len, int value) {
  int cntr = 0;
  for (int i = 0; i < len; i++) {
    int right = len;
    int left = i;
    while (left < right - 1) {
      int midle = (left + right) / 2;
      if (arr[i] + arr[midle] == value) {
        cntr++;
        int t = midle + 1;
        while ((arr[i] + arr[t] == value) && (t < right)) {
          cntr++;
          t++;
        }
        t = midle - 1;
        while ((arr[i] + arr[t] == value) && (t > left)) {
          cntr++;
          t--;
        }
        break;
      } else if (arr[i] + arr[midle] > value) {
        right = midle;
      } else {
        left = midle;
      }
    }
  }
  return cntr;
}
