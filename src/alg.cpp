// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
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
int countPairs2(int *arr, int len, int value) {
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
  if (count == 0) {
    return 0;
  } else {
    return count;
  }
}
int cbinsearch(int* arr, int size, int value) {
  int count = 0;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == value) {
          count++;
          int i = mid + 1;
          while (i < size && arr[i] == value) {
              count++;
              i++;
          }
          i = mid - 1;
          while (i >= 0 && arr[i] == value) {
              count++;
              i--;
          }
          return count;
      } else if (arr[mid] < value) {
          left = mid + 1;
      } else {
          right = mid - 1;
      }
  }
  return count;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  int i = 0;
  while (i < len) {
      int number = value - arr[i];
      count = count + cbinsearch(&arr[i + 1], len - i - 1, number);
      i++;
  }
  return count;
}
