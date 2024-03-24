// Copyright 2021 NNTU-CS

int countPairs1(int * arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int * arr, int len, int value) {
  int count = 0;
  int max = 0;
  for (int i = 0; i < len; ++i) {
    if (arr[i] > value) {
      max = i;
    }
  }
  for (int i = 0; i < max; i++) {
    for (int j = i + 1; j < max; j++) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
    }
  }
  return count;
}

int cbinsearch(int * arr, int size, int value) {
  int count = 0;
  int left = 0, righ = size - 1;
  while (left < righ) {
    int mid = (left + righ) / 2;
    if (arr[mid] == value) {
      int a = mid - 1;
      while (arr[mid] == value) {
        if (arr[mid] == value) {
          count++;
          mid++;
        }
      }
      while (arr[a] == value) {
        if (arr[a] == value) {
          count++;
          --a;
        }
      }
      return count;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      righ = mid - 1;
    }
  }
  return count;
}

int countPairs3(int * arr, int len, int value) {
  int count = 0;
  int i = 0;
  while (arr[i] <= (value / 2) - 1) {
    int two = value - arr[i];
    count += cbinsearch(arr, len, two);
    i++;
  }
  int midd = cbinsearch(arr, len, value / 2);
  count += midd * ((midd - 1)) / 2;
  return count;
}
