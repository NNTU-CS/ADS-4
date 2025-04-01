// Copyright 2021 NNTU-CS

int countPairs1(const int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
        while (j + 1 < len && arr[j] == arr[j + 1])
          j++;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1])
      i++;
  }
  return count;
}

int countPairs2(const int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }

      int left_count = 1;
      int right_count = 1;

      while (left + 1 < right && arr[left] == arr[left + 1]) {
        left_count++;
        left++;
      }

      while (right - 1 > left && arr[right] == arr[right - 1]) {
        right_count++;
        right--;
      }

      count += left_count * right_count;
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

int binarySearch(const int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(const int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    if (target < arr[i])
      break;

    int pos = binarySearch(arr, i + 1, len - 1, target);
    if (pos != -1) {
      count++;
      int right = pos + 1;
      while (right < len && arr[right] == target) {
        count++;
        right++;
      }
      int left = pos - 1;
      while (left > i && arr[left] == target) {
        count++;
        left--;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1])
      i++;
  }
  return count;
}
