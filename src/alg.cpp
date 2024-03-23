// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  if (count == 0)
    return 0;
  else
    return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while (arr[right] > value) {
    right--;
  }
  for (int left = 0; left < right; left++) {
    for (int r = right; left < r; r--) {
      if (arr[left] + arr[r] == value) {
        count++;
      }
    }
  }
  if (count == 0)
    return 0;
  else
    return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int left = i + 1;
    int right = len - 1;
    int sumChar = value - arr[i];
    while (left <= right) {
      int midInd = (left + right) / 2;
      if (arr[midInd] == sumChar) {
        count++;
        int mid = midInd - 1;
        while ((mid > i) && (arr[mid] == arr[midInd])) {
          count++;
          mid--;
        }
        int na = midInd + 1;
        while ((i < na) && (arr[na] == arr[midInd])) {
          count++;
          na++;
        }
        break;
      } else if (arr[midInd] > sumChar) {
        right = midInd - 1;
      } else {
        left = midInd + 1;
      }
    }
  }
  if (count)
    return count;
  else
    return 0;
}
