// Copyright 2021 NNTU-CS
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
        break;
      }
      if (pairSum > sum) break;
      inner++;
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

int locateFirstMatch(int *data, int start, int end, int goal) {
  int earliest = -1;
  int lower = start;
  int upper = end;
  while (lower <= upper) {
    int middle = lower + (upper - lower) / 2;
    if (data[middle] < goal) {
      lower = middle + 1;
    } else {
      if (data[middle] == goal) earliest = middle;
      upper = middle - 1;
    }
  }
  return earliest;
}

int locateLastMatch(int *values, int begin, int finish, int aim) {
  int latest = -1;
  int low = begin;
  int high = finish;
  while (low <= high) {
    int center = low + (high - low) / 2;
    if (values[center] > aim) {
      high = center - 1;
    } else {
      if (values[center] == aim) latest = center;
      low = center + 1;
    }
  }
  return latest;
}

int countPairs3(int *sequence, int count, int desired) {
  int matches = 0;
  int position = 0;
  while (position < count - 1) {
    int complement = desired - sequence[position];
    int first = locateFirstMatch(sequence, position + 1,
                                 count - 1, complement);
    if (first == -1) {
      position++;
      continue;
    }
    int last = locateLastMatch(sequence, position + 1,
                               count - 1, complement);
    matches += (last - first + 1);
    while (position < count - 1 &&
           sequence[position] == sequence[position + 1]) {
      position++;
    }
    position++;
  }
  return matches;
}
