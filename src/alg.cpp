// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value)
        count++;
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int num = right - left + 1;
        count += num * (num - 1) / 2;
        break;
      } else {
        int cntLeft = 1;
        int cntRight = 1;
        while (left + cntLeft < right && arr[left + cntLeft] == arr[left]) {
          cntLeft++;
        }
        while (right - cntRight > left && arr[right - cntRight] == arr[right]) {
          cntRight++;
        }
        count += cntLeft * cntRight;
        left += cntLeft;
        right -= cntRight;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
      return mid; 
    else if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1; 
}
int lowerBound(int *arr, int left, int right, int target) {
  int res = right + 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= target) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}
int upperBound(int *arr, int left, int right, int target) {
  int res = right + 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] > target) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int idx = binarySearch(arr, i + 1, len - 1, target);
    if (idx != -1) {
      int low = lowerBound(arr, i + 1, len - 1, target);
      int high = upperBound(arr, i + 1, len - 1, target);
      count += high - low;
    }
  }
  return count;
}
