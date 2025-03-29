// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int temp;
  int left = 0;
  int right = len-1;
  int count = 0;
  while ((right > 0) && (right > value)) {
    right--;
  }
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      temp = right-1;
      while ((left < temp) && (arr[left] + arr[temp] == value)) {
        count++;
        temp--;
      }
      left++;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int binarySearch(int* arr, int left, int right, int value) {
  int count = 0, check;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      count++;
      check = mid-1;
      while ((check >= left) && (arr[check] == value)) {
        count++;
        check--;
      }
      check = mid + 1;
      while ((check <= right) && (arr[check] == value)) {
        count++;
        check++;
      }
      return count;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int complement = value - arr[i];
    if (complement > 0) {
      count += binarySearch(arr, i+1, len-1, complement);
    }
  }
  return count;
}
