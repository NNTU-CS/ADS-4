// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        n++;
      }
    }
  }
  return n;
}

int countPairs2(int *arr, int len, int value) {
  int n = 0;
  int x = len - 1;
  while (arr[x] > value) {
    x--;
  }
  for (int i = 0; i < x; i++) {
    if (arr[i] < value) {
      for (int j = x; j > i; j--) {
        if ((arr[i] + arr[j]) == value) {
          n++;
          if ((arr[i] + arr[j - 1]) != value) break;
        }
      }
    }
  }
  return n;
}

int countPairs3(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len; ++i) {
    int low = i + 1;
    int high = len - 1;
    int y = value - arr[i];
    while (low <= high) {
      int mid = (low + high) / 2;
      if (arr[mid] == y) {
        n++;
        int net = mid - 1;
        while ((net > i) && (arr[mid] == arr[net])) {
          n++;
          net--;
        }
        net = mid + 1;
        while ((i < net) && (arr[net] == arr[mid])) {
          n++;
          net++;
        }
        break;
      } else if (arr[mid] > y) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }
  return n;
}
