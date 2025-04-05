// Copyright 2021 NNTU-CS
#include <algorithm>
#include <iostream>
#include <vector>

void sortArray(int *data, int arrayLength) {
  for (int i = 1; i < arrayLength; ++i) {
    int currentElement = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > currentElement) {
      data[j + 1] = data[j];
      --j;
    }
    data[j + 1] = currentElement;
  }
}

int countPairs1(int *inputArray, int arrayLength, int targetValue) {
  int pairCount = 0;
  for (int i = 0; i < arrayLength; ++i) {
    for (int j = i + 1; j < arrayLength; ++j) {
      if (inputArray[i] + inputArray[j] == targetValue) {
        ++pairCount;
      }
    }
  }
  return pairCount;
}

int countPairs2(int *inputArray, int arrayLength, int targetValue) {
  int pairCount = 0;
  int leftIndex = 0;
  int rightIndex = arrayLength - 1;

  while (leftIndex < rightIndex) {
    int currentSum = inputArray[leftIndex] + inputArray[rightIndex];

    if (currentSum == targetValue) {
      if (inputArray[leftIndex] == inputArray[rightIndex]) {
        int numElements = rightIndex - leftIndex + 1;
        pairCount += numElements * (numElements - 1) / 2;
        break;
      } else {
        int leftValue = inputArray[leftIndex];
        int leftOccurrenceCount = 0;
        while (leftIndex < arrayLength && inputArray[leftIndex] == leftValue) {
          ++leftOccurrenceCount;
          ++leftIndex;
        }

        int rightValue = inputArray[rightIndex];
        int rightOccurrenceCount = 0;
        while (rightIndex >= 0 && inputArray[rightIndex] == rightValue) {
          ++rightOccurrenceCount;
          --rightIndex;
        }
        pairCount += leftOccurrenceCount * rightOccurrenceCount;
      }
    } else if (currentSum < targetValue) {
      ++leftIndex;
    } else {
      --rightIndex;
    }
  }

  return pairCount;
}

int findLowerBoundIndex(int *arr, int len, int target, int start) {
  int low = start;
  int high = len;
  while (low < high) {
    int middle = low + (high - low) / 2;
    if (arr[middle] < target) {
      low = middle + 1;
    } else {
      high = middle;
    }
  }
  return (low < len && arr[low] == target) ? low : -1;
}

int findUpperBoundIndex(int *arr, int len, int target, int start) {
  int low = start;
  int high = len;
  while (low < high) {
    int middle = low + (high - low) / 2;
    if (arr[middle] <= target) {
      low = middle + 1;
    } else {
      high = middle;
    }
  }
  return low;
}

int countPairs3(int *inputArray, int arrayLength, int targetValue) {
  int pairCount = 0;

  for (int i = 0; i < arrayLength;) {
    int currentValue = inputArray[i];
    int currentOccurrenceCount = 0;
    while (i < arrayLength && inputArray[i] == currentValue) {
      ++currentOccurrenceCount;
      ++i;
    }

    int complementValue = targetValue - currentValue;

    if (currentValue > complementValue) break;
    if (currentValue == complementValue) {
      pairCount += currentOccurrenceCount * (currentOccurrenceCount - 1) / 2;
    } else {
      int lowerIndex =
          findLowerBoundIndex(inputArray, arrayLength, complementValue, i);
      if (lowerIndex == -1) continue;

      int upperIndex =
          findUpperBoundIndex(inputArray, arrayLength, complementValue, i);
      int complementOccurrenceCount = upperIndex - lowerIndex;

      pairCount += currentOccurrenceCount * complementOccurrenceCount;
    }
  }

  return pairCount;
}
