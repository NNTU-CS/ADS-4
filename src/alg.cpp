// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] == arr[i - 1]) continue;
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
        break;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int currentSum = arr[left] + arr[right];
    if (currentSum == value) {
      count++;
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1]) {
        left++;
      }
      while (left < right && arr[right] == arr[right + 1]) {
        right--;
      }
    } else if (currentSum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        count++;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1]) i++;
  }
  return count;
}
