// Copyright 2021 NNTU-CS

void sortByInsertion(int data[], int size) {
  for (int idx = 1; idx < size; ++idx) {
    int temp = data[idx];
    int pos = idx - 1;
    while (pos >= 0 && data[pos] > temp) {
      data[pos + 1] = data[pos];
      pos--;
    }
    data[pos + 1] = temp;
  }
}

int findPairCount1(int *data, int length, int targetSum) {
  int pairCount = 0;
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (data[i] + data[j] == targetSum) pairCount++;
    }
  }
  return pairCount;
}

int findPairCount2(int *data, int length, int targetSum) {
  int pairCount = 0;
  int leftPointer = 0, rightPointer = length - 1;
  while (leftPointer < rightPointer) {
    int currentSum = data[leftPointer] + data[rightPointer];
    if (currentSum == targetSum) {
      if (data[leftPointer] == data[rightPointer]) {
        int groupSize = rightPointer - leftPointer + 1;
        pairCount += groupSize * (groupSize - 1) / 2;
        break;
      } else {
        int leftValue = data[leftPointer], leftCount = 0;
        while (leftPointer < length && data[leftPointer] == leftValue) {
          leftCount++;
          leftPointer++;
        }
        int rightValue = data[rightPointer], rightCount = 0;
        while (rightPointer >= 0 && data[rightPointer] == rightValue) {
          rightCount++;
          rightPointer--;
        }
        pairCount += leftCount * rightCount;
      }
    } else if (currentSum < targetSum) {
      leftPointer++;
    } else {
      rightPointer--;
    }
  }
  return pairCount;
}

int findLowerBound(int *data, int length, int targetValue, int startIdx) {
  int low = startIdx, high = length;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (data[mid] < targetValue)
      low = mid + 1;
    else
      high = mid;
  }
  return (low < length && data[low] == targetValue) ? low : -1;
}

int findUpperBound(int *data, int length, int targetValue, int startIdx) {
  int low = startIdx, high = length;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (data[mid] <= targetValue)
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}

int findPairCount3(int *data, int length, int targetSum) {
  int pairCount = 0;

  for (int i = 0; i < length;) {
    int currentValue = data[i];
    int currentValueCount = 0;
    while (i < length && data[i] == currentValue) {
      currentValueCount++;
      i++;
    }
    int requiredValue = targetSum - currentValue;

    if (currentValue > requiredValue) break;
    if (currentValue == requiredValue) {
      pairCount += currentValueCount * (currentValueCount - 1) / 2;
    } else {
      int lowerBoundIdx = findLowerBound(data, length, requiredValue, i);
      if (lowerBoundIdx == -1) continue;
      int upperBoundIdx = findUpperBound(data, length, requiredValue, i);
      int requiredValueCount = upperBoundIdx - lowerBoundIdx;
      pairCount += currentValueCount * requiredValueCount;
    }
  }
  return pairCount;
}

