// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      } else if (arr[i] + arr[j] > value) {
        break;
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
      int leftVal = arr[left];
      int rightVal = arr[right];

      int lCount = 0;
      while (left < right && arr[left] == leftVal) {
        ++lCount;
        ++left;
      }

      int rCount = 0;
      while (right >= left && arr[right] == rightVal) {
        ++rCount;
        --right;
      }

      count += lCount * rCount;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }

  return count;
}

int lowerBound(int *arr, int left, int right, int target) {
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int upperBound(int *arr, int left, int right, int target) {
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    int lb = lowerBound(arr, i + 1, len, complement);
    int ub = upperBound(arr, i + 1, len, complement);
    count += (ub - lb);
  }
  return count;
}
