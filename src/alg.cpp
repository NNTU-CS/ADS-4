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
  int count = 0, left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int num = right - left + 1;
        count += num * (num - 1) / 2;
        break;
      }
      int cntLeft = 1, cntRight = 1;
      while (left + cntLeft < right && arr[left + cntLeft] == arr[left]) cntLeft++;
      while (right - cntRight > left && arr[right - cntRight] == arr[right]) cntRight++;
      count += cntLeft * cntRight;
      left += cntLeft;
      right -= cntRight;
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
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int index = binarySearch(arr, i + 1, len - 1, target);
    if (index != -1) {
      int cnt = 1;
      int l = index - 1, r = index + 1;
      while (l > i && arr[l] == target) {
        cnt++;
        l--;
      }
      while (r < len && arr[r] == target) {
        cnt++;
        r++;
      }
      count += cnt;
    }
  }
  return count;
}
