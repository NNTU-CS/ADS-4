// Copyright 2021 NNTU-CS
int countPairs1(int *array, int size, int sum) {
  int total = 0;
  int outer = 0;
  while (outer < size - 1) {
    int inner = outer + 1;
    while (inner < size) {
      int pairSum = array[outer] + array[inner];
      if (pairSum == sum) {
        total++;
        while (inner < size - 1 && array[inner] == array[inner + 1]) {
          inner++;
        }
        break;
      }
      if (pairSum > sum) break;
      inner++;
    }
    while (outer < size - 1 && array[outer] == array[outer + 1]) {
      outer++;
    }
    outer++;
  }
  return total;
}

int countPairs2(int *numbers, int length, int target) {
  int pairs = 0;
  int left = 0;
  int right = length - 1;
  while (left < right) {
    int currentSum = numbers[left] + numbers[right];
    if (currentSum == target) {
      pairs++;
      while (left < right && numbers[left] == numbers[left + 1]) left++;
      while (left < right && numbers[right] == numbers[right - 1]) right--;
      left++;
      right--;
    } else if (currentSum < target) {
      left++;
    } else {
      right--;
    }
  }
  return pairs;
}

int findMatch(int *data, int start, int end, int goal) {
  int lower = start;
  int upper = end;
  while (lower <= upper) {
    int middle = (lower + upper) >> 1;
    int value = data[middle];
    if (value == goal) return middle;
    if (value < goal) lower = middle + 1;
    else upper = middle - 1;
  }
  return -1;
}

int countPairs3(int *sequence, int count, int desired) {
  int matches = 0;
  int position = 0;
  while (position < count - 1) {
    int complement = desired - sequence[position];
    if (complement < 0) {
      position++;
      continue;
    }
    int match = findMatch(sequence, position + 1, count - 1, complement);
    if (match != -1) {
      matches++;
      while (match < count - 1 && sequence[match] == sequence[match + 1]) {
        match++;
      }
    }
    int current = sequence[position];
    while (position < count - 1 && sequence[position] == current) {
      position++;
    }
  }
  return matches;
}
