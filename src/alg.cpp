// Copyright 2021 NNTU-CS
#include <algorithm>

void myInsertionSort(int* data, int size) {
  for (int i = 1; i < size; ++i) {
    int currentValue = data[i];
    int j = i - 1;

    while (j >= 0 && data[j] > currentValue) {
      data[j + 1] = data[j];
      j--;
    }

    data[j + 1] = currentValue;
  }
}

int countMatchingPairs_Naive(int* array, int arrayLength, int targetSum) {
  int pairCount = 0;
  for (int i = 0; i < arrayLength; ++i) {
    for (int j = i + 1; j < arrayLength; ++j) {
      if (array[i] + array[j] == targetSum) {
        pairCount++;
      }
    }
  }
  return pairCount;
}

int countMatchingPairs_TwoPointers(int* array, int arrayLength, int targetSum) {
  int pairCount = 0;
  int leftIndex = 0;
  int rightIndex = arrayLength - 1;

  while (leftIndex < rightIndex) {
    int currentSum = array[leftIndex] + array[rightIndex];

    if (currentSum == targetSum) {
      if (array[leftIndex] == array[rightIndex]) {
        int numEqual = rightIndex - leftIndex + 1;
        pairCount += numEqual * (numEqual - 1) / 2;
        break;
      } else {
        int leftValue = array[leftIndex];
        int leftCount = 0;
        while (leftIndex < arrayLength && array[leftIndex] == leftValue) {
          leftCount++;
          leftIndex++;
        }

        int rightValue = array[rightIndex];
        int rightCount = 0;
        while (rightIndex >= 0 && array[rightIndex] == rightValue) {
          rightCount++;
          rightIndex--;
        }

        pairCount += leftCount * rightCount;
      }
    } else if (currentSum < targetSum) {
      leftIndex++;
    } else {
      rightIndex--;
    }
  }
  return pairCount;
}

int findLowerBoundIndex(int* array, int arrayLength, int targetValue,
                        int startIndex) {
  int low = startIndex;
  int high = arrayLength;

  while (low < high) {
    int middle = low + (high - low) / 2;

    if (array[middle] < targetValue) {
      low = middle + 1;
    } else {
      high = middle;
    }
  }

  return (low < arrayLength && array[low] == targetValue) ? low : -1;
}

int findUpperBoundIndex(int* array, int arrayLength, int targetValue,
                        int startIndex) {
  int low = startIndex;
  int high = arrayLength;

  while (low < high) {
    int middle = low + (high - low) / 2;

    if (array[middle] <= targetValue) {
      low = middle + 1;
    } else {
      high = middle;
    }
  }

  return low;
}

int countMatchingPairs_BinarySearch(int* array, int arrayLength,
                                    int targetSum) {
  int pairCount = 0;

  for (int i = 0; i < arrayLength;) {
    int currentValue = array[i];
    int currentCount = 0;

    while (i < arrayLength && array[i] == currentValue) {
      currentCount++;
      i++;
    }

    int complementValue = targetSum - currentValue;

    if (currentValue > complementValue) {
      break;
    }

    if (currentValue == complementValue) {
      pairCount += currentCount * (currentCount - 1) / 2;
    } else {
      int lowerIndex =
          findLowerBoundIndex(array, arrayLength, complementValue, i);
      if (lowerIndex == -1) {
        continue;
      }

      int upperIndex =
          findUpperBoundIndex(array, arrayLength, complementValue, i);

      int complementCount = upperIndex - lowerIndex;

      pairCount += currentCount * complementCount;
    }
  }

  return pairCount;
}
