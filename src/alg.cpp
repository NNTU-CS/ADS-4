// Copyright 2021 NNTU-CS
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int leftVal = arr[left], countLeft = 0;
        while (left < len && arr[left] == leftVal) {
          countLeft++;
          left++;
        }
        int rightVal = arr[right], countRight = 0;
        while (right >= 0 && arr[right] == rightVal) {
          countRight++;
          right--;
        }
        count += countLeft * countRight;
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
  for (int i = 0; i < len; i++) {
    if (arr[i] > value - arr[i]) break;
    int complement = value - arr[i];
    int lo = i + 1, hi = len - 1, first = -1, last = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] < complement)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    if (lo < len && arr[lo] == complement)
      first = lo;
    else
      continue;
    lo = i + 1;
    hi = len - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] <= complement)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    last = hi;
    count += (last - first + 1);
  }
  return count;
}
