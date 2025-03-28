// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairCount = 0;
  for (int x = 0; x < len - 1; x++) {
    for (int y = x + 1; y < len; y++) {
      if (arr[x] + arr[y] == value) {
        pairCount++;
      }
    }
  }
  return pairCount;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int limit = len - 1;
  while (limit > 0 && arr[limit] > value) {
    limit--;
  }
  for (int left = 0; left < len; left++) {
    for (int right = limit; right > left; right--) {
      if (arr[left] + arr[right] == value) {
        count++;
      }
    }
  }
  return count;
}

int binarySearchCount(int *array, int start, int end, int key) {
  int firstOccurrence = -1, lastOccurrence = -1;
  int low = start, high = end;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] >= key) {
      if (array[mid] == key) {
        firstOccurrence = mid;
      }
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (firstOccurrence == -1) return 0;
  low = firstOccurrence;
  high = end;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] <= key) {
      if (array[mid] == key) {
        lastOccurrence = mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return (lastOccurrence - firstOccurrence) + 1;
}

int countPairs3(int *arr, int len, int value) {
  int totalPairs = 0;
  for (int i = 0; i < len; i++) {
    totalPairs += binarySearchCount(arr, i + 1, len - 1, value - arr[i]);
  }
  return totalPairs;
}
