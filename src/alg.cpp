// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  iint count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
        while (j + 1 < len && arr[j] == arr[j + 1]) j++;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1]) i++;
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      while (left < right && arr[left] == arr[left + 1]) left++;
      while (left < right && arr[right] == arr[right - 1]) right--;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int countOccurrences(int *arr, int low, int high, int value) {
  int first = -1, last = -1;
  int left = low, right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      first = mid;
      right = mid - 1;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  if (first == -1)
    return 0;
  left = low, right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      last = mid;
      left = mid + 1;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return last - first + 1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    count += countOccurrences(arr, i + 1, len - 1, value - arr[i]);
    while (i + 1 < len && arr[i] == arr[i + 1]) i++;
  }
  return count;
}
