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
  int count = 0, i = 0;
  while (i < len) {
    int a = arr[i];
    if (a > value - a) break;
    int countA = 0;
    while (i < len && arr[i] == a) {
      countA++;
      i++;
    }
    int complement = value - a;
    int lo = 0, hi = len - 1, firstIndex = -1, lastIndex = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] < complement)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    if (lo < len && arr[lo] == complement)
      firstIndex = lo;
    else
      continue;
    lo = 0, hi = len - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] <= complement)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    lastIndex = hi;
    int countB = lastIndex - firstIndex + 1;
    if (a == complement)
      count += countA * (countA - 1) / 2;
    else
      count += countA * countB;
  }
  return count;
}
