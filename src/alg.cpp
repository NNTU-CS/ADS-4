// Copyright 2023 Your Name

#include <algorithm>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
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
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int current_left = arr[left];
        int current_right = arr[right];
        int left_count = 0;
        int right_count = 0;

        while (left < len && arr[left] == current_left) {
          ++left;
          ++left_count;
        }

        while (right >= 0 && arr[right] == current_right) {
          --right;
          ++right_count;
        }

        count += left_count * right_count;
      }
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int countOccurrences(int *arr, int left, int right, int target) {
  if (left > right) return 0;
  int first = -1;
  int low = left, high = right;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target) {
      if (arr[mid] == target) first = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = -1;
  low = first, high = right;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) {
      if (arr[mid] == target) last = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  std::sort(arr, arr + len);
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < arr[i]) continue;
    count += countOccurrences(arr, i + 1, len - 1, target);
  }
  return count;
}
