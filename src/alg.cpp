// Copyright 2021 NNTU-CS
int countPairs1(int const *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)count++;
    }
  }
  return count;
}
int countPairs2(int const *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}
int binary(int const *arr, int low, int high, int value) {
  int first = -1;
  int left = low, right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= value) {
      right = mid - 1;
      if (arr[mid] == value) first = mid;
    } else {
      left = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  left = first;
  right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= value) {
      left = mid + 1;
      if (arr[mid] == value) last = mid;
    } else {
      right = mid - 1;
    }
  }

  return last - first + 1;
}

int countPairs3(int const *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    count += binary(arr, i + 1, len - 1, value - arr[i]);
  }
  return count;
}
