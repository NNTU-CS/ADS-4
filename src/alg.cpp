// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
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

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    const int sum = arr[left] + arr[right];
    if (sum < value) {
      ++left;
    } else if (sum > value) {
      --right;
    } else {
      if (arr[left] == arr[right]) {
        const int duplicates = right - left + 1;
        count += duplicates * (duplicates - 1) / 2;
        break;
      }

      int left_dup = 1;
      while (left + left_dup < right &&
             arr[left + left_dup] == arr[left]) {
        ++left_dup;
      }

      int right_dup = 1;
      while (left < right - right_dup &&
             arr[right - right_dup] == arr[right]) {
        ++right_dup;
      }

      count += left_dup * right_dup;
      left += left_dup;
      right -= right_dup;
    }
  }
  return count;
}

int binarySearchFirst(const int* arr, int high, int low, int target) {
  int result = -1;
  while (low <= high) {
    const int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      result = mid;
      high = mid - 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}

int binarySearchLast(const int* arr, int high, int low, int target) {
  int result = -1;
  while (low <= high) {
    const int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      result = mid;
      low = mid + 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    const int target = value - arr[i];
    if (target < arr[i]) {
      continue;
    }

    const int low = i + 1;
    const int high = len - 1;
    const int first = binarySearchFirst(arr, high, low, target);
    if (first == -1) {
      continue;
    }

    const int last = binarySearchLast(arr, high, first, target);
    count += (last - first + 1);
  }
  return count;
}
