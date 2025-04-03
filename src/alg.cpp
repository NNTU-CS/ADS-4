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

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        int l = mid - 1;
        while (l >= left && arr[i] + arr[l] == value) {
          count++;
          l--;
        }
        int r = mid + 1;
        while (r <= right && arr[i] + arr[r] == value) {
          count++;
          r++;
        }
        break;
      } else if (arr[i] + arr[mid] < value) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] != arr[right]) {
        int left_val = arr[left];
        int right_val = arr[right];
        int left_count = 1;
        int right_count = 1;
        while (left + 1 < right && arr[left + 1] == left_val) {
          left++;
          left_count++;
        }
        while (right - 1 > left && arr[right - 1] == right_val) {
          right--;
          right_count++;
        }
        count += left_count * right_count;
        left++;
        right--;
      } else {
        count += (right - left + 1) * (right - left) / 2;
        break;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
