// Copyright 2021 NNTU-CS
#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(int *data, int length) {
  for (int idx = 1; idx < length; ++idx) {
    int value = data[idx];
    int pos = idx - 1;
    while (pos >= 0 && data[pos] > value) {
      data[pos + 1] = data[pos];
      --pos;
    }
    data[pos + 1] = value;
  }
}

int bruteForcePairCount(int *data, int length, int targetSum) {
  int total = 0;
  for (int a = 0; a < length; ++a) {
    for (int b = a + 1; b < length; ++b) {
      if (data[a] + data[b] == targetSum) {
        ++total;
      }
    }
  }
  return total;
}

int optimizedPairCount(int *data, int length, int targetSum) {
  int total = 0;
  int start = 0;
  int end = length - 1;

  while (start < end) {
    int sum = data[start] + data[end];

    if (sum == targetSum) {
      if (data[start] == data[end]) {
        int range = end - start + 1;
        total += range * (range - 1) / 2;
        break;
      } else {
        int leftValue = data[start];
        int leftDup = 0;
        while (start < length && data[start] == leftValue) {
          ++leftDup;
          ++start;
        }

        int rightValue = data[end];
        int rightDup = 0;
        while (end >= 0 && data[end] == rightValue) {
          ++rightDup;
          --end;
        }

        total += leftDup * rightDup;
      }
    } else if (sum < targetSum) {
      ++start;
    } else {
      --end;
    }
  }

  return total;
}

int getLowerIndex(int *data, int length, int value, int from) {
  int low = from;
  int high = length;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (data[mid] < value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return (low < length && data[low] == value) ? low : -1;
}

int getUpperIndex(int *data, int length, int value, int from) {
  int low = from;
  int high = length;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (data[mid] <= value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int frequencyBasedPairCount(int *data, int length, int targetSum) {
  int total = 0;
  int idx = 0;

  while (idx < length) {
    int val = data[idx];
    int freq = 0;

    while (idx < length && data[idx] == val) {
      ++freq;
      ++idx;
    }

    int counterpart = targetSum - val;
    if (val > counterpart) break;

    if (val == counterpart) {
      total += freq * (freq - 1) / 2;
    } else {
      int lower = getLowerIndex(data, length, counterpart, idx);
      if (lower == -1) continue;

      int upper = getUpperIndex(data, length, counterpart, idx);
      int count = upper - lower;

      total += freq * count;
    }
  }

  return total;
}
