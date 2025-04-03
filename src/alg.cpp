// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int binarySearch(int* arr, int left, int right, int target, bool find_first) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            if (find_first) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int tgt = value - arr[i];
        int first = binarySearch(arr, i + 1, len - 1, tgt, true);
        if (first != -1) {
            int last = binarySearch(arr, first, len - 1, tgt, false);
            count += last - first + 1;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int summ = arr[left] + arr[right];
    if (summ == value) {
      count++;
      while (left < right && arr[left] == arr[left + 1]) left++;
      while (left < right && arr[right] == arr[right - 1]) right--;
      left++;
      right--;
    } else if (summ < value) {
      left++;
    } else {
      right--;
    }
  }
}
