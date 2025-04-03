// Copyright 2021 NNTU-CS
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void insertionSort(int* arr, int low, int high) {
  for (int i = low + 1; i <= high; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= low && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void quickSort(int* arr, int low, int high) {
  if (low < high) {
    if (high - low + 1 <= 10) {
      insertionSort(arr, low, high);
      return;
    }
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high - 1]);
    int pivot = arr[high - 1];

    int i = low;
    int j = high - 1;
    while (true) {
      while (arr[++i] < pivot) {
      }
      while (arr[--j] > pivot) {
      }
      if (i >= j) break;
      swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[high - 1]);
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
  }
}

void sortArray(int* arr, int len) {
  if (len <= 1) return;
  quickSort(arr, 0, len - 1);
}

int countPairs1(int* arr, int len, int value) {
  sortArray(arr, len);
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  sortArray(arr, len);
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum < value) {
      left++;
    } else if (sum > value) {
      right--;
    } else {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftVal = arr[left], rightVal = arr[right];
      int leftCount = 0, rightCount = 0;
      while (left < len && arr[left] == leftVal) {
        leftCount++;
        left++;
      }
      while (right >= 0 && arr[right] == rightVal) {
        rightCount++;
        right--;
      }
      count += leftCount * rightCount;
    }
  }
  return count;
}

int lowerBound(int* arr, int start, int end, int target) {
  int low = start, high = end;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}

int upperBound(int* arr, int start, int end, int target) {
  int low = start, high = end;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target)
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}
int countPairs3(int* arr, int len, int value) {
  sortArray(arr, len);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int lb = lowerBound(arr, i + 1, len, target);
    if (lb == len || arr[lb] != target) continue;
    int ub = upperBound(arr, i + 1, len, target);
    count += (ub - lb);
  }
  return count;
}
