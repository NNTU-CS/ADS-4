// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
int count = 0, left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int cntLeft = 1, cntRight = 1;
      while (left + cntLeft < right && arr[left + cntLeft] == arr[left]) cntLeft++;
      while (right - cntRight > left && arr[right - cntRight] == arr[right]) cntRight++;
      if (arr[left] == arr[right]) {
        count += (right - left + 1) * (right - left) / 2;
        break;
      } else {
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
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int left = i + 1, right = len - 1;
    while (left <= right) {
      int mid = left + ((right - left) / 2);
      if (arr[mid] == target) {
        count++;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
