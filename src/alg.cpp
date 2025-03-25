// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
          if (arr[i] + arr[j] == value) {
              count++;
          }
      }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int end = len - 1;
  while (end > 0) {
      if (arr[end] > value) {
          end--;
      }
      else {
          break;
      }
  }
  for (int i = 0; i < len; i++) {
      for (int j = end; j > i; j--) {
          if (arr[i] + arr[j] == value)
              count++;
      }
  }
  return count;
}

int binSearch(int* arr, int low, int high, int value) {
  int fst = -1;
  int left = low, right = high;
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] >= value) {
          right = mid - 1;
          if (arr[mid] == value) {
              fst = mid;
          }
      } else {
          left = mid + 1;
      }
  }
  if (fst == -1) {
      return 0;
  }
  int last = fst;
  left = fst;
  right = high;
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] <= value) {
          left = mid + 1;
          if (arr[mid] == value) {
              last = mid;
          }
      } else {
          right = mid - 1;
      }
  }
  return last - fst + 1;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
      count += binSearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return count;
}
