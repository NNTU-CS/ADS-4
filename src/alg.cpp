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
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int cntLeft = 1, cntRight = 1;
        while (left + cntLeft < right && arr[left] == arr[left + cntLeft]) cntLeft++;
        while (right - cntRight > left && arr[right] == arr[right - cntRight]) cntRight++;
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
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int duplicates = 1;
        int l = mid - 1, r = mid + 1;
        while (l >= left && arr[l] == target) {
          duplicates++;
          l--;
        }
        while (r <= right && arr[r] == target) {
          duplicates++;
          r++;
        }
        count += duplicates;
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
