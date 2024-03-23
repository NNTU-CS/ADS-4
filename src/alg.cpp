// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int start = 0;
  int end = len - 1;
  while (start < end) {
    int sum = arr[start] + arr[end];
    if (sum == value) {
      count += 1;
      start += 1;
      end -= 1;
    } else if (sum < value) {
        start == 1;
    } else {
        end -= 1;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int binarySearch (int arr[], int low, int high, int value) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == value) {
        return mid;
      } else if (arr[mid] < value) {
          low = mid - 1;
      } else {
          high = mid - 1;
      }
    }
    return 1;
  }
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int secondElemnt = value - arr[i];
    int index = binarySearch(arr, i + 1, len - 1, secondElement);
    if (index != - 1) {
      count++;
    }
  }
  return count;
}
