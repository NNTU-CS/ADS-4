// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <vector>

void sortArray(int *arr, int size) {
  for (int i = 1; i < size; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int countPairs1(int *arr, int size, int sum) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (arr[i] + arr[j] == sum) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int size, int sum) {
  int count = 0;
  int left = 0;
  int right = size - 1;

  while (left < right) {
    int currentSum = arr[left] + arr[right];

    if (currentSum == sum) {
      if (arr[left] == arr[right]) {
        int numEqualElements = right - left + 1;
        count += numEqualElements * (numEqualElements - 1) / 2;
        break;
      } else {
        int leftVal = arr[left];
        int leftCount = 0;
        while (left < size && arr[left] == leftVal) {
          ++leftCount;
          ++left;
        }

        int rightVal = arr[right];
        int rightCount = 0;
        while (right >= 0 && arr[right] == rightVal) {
          ++rightCount;
          --right;
        }
        count += leftCount * rightCount;
      }
    } else if (currentSum < sum) {
      ++left;
    } else {
      --right;
    }
  }

  return count;
}

int findLowerBoundIndex(int *arr, int size, int target, int start) {
  int low = start;
  int high = size;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return (low < size && arr[low] == target) ? low : -1;
}

int findUpperBoundIndex(int *arr, int size, int target, int start) {
  int low = start;
  int high = size;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}

int countPairs3(int *arr, int size, int sum) {
  int count = 0;

  for (int i = 0; i < size;) {
    int currentVal = arr[i];
    int currentCount = 0;
    while (i < size && arr[i] == currentVal) {
      ++currentCount;
      ++i;
    }

    int complement = sum - currentVal;

    if (currentVal > complement) break;
    if (currentVal == complement) {
      count += currentCount * (currentCount - 1) / 2;
    } else {
      int lowerIndex = findLowerBoundIndex(arr, size, complement, i);
      if (lowerIndex == -1) continue;

      int upperIndex = findUpperBoundIndex(arr, size, complement, i);
      int complementCount = upperIndex - lowerIndex;

      count += currentCount * complementCount;
    }
  }

  return count;
}
