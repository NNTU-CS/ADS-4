// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0, left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int left_val = arr[left];
      int right_val = arr[right];
      int left_count = 0, right_count = 0;
      while (left < len && arr[left] == left_val) {
        left++;
        left_count++;
      }
      while (right >= 0 && arr[right] == right_val) {
        right--;
        right_count++;
      }
      count += left_count * right_count;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int binaryLast(int *arr, int left, int right, int targ) {
  int last = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == targ) {
      last = mid;
      left = mid + 1;
    } else if (arr[mid] < targ) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return last;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int targ = value - arr[i];
    int first = 1 + i;
    int last = binaryLast(arr, first, len - 1, targ);
    if (last != -1) {
      count += last - first - 1;
    }
  }  
  return count;
}
