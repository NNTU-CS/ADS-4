// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  int pos = 0;
  while (pos < len - 1) {
    int next = pos + 1;
    while (next < len) {
      if (arr[pos] + arr[next] == value) {
        count += 1;
      }
      next++;
    }
    pos++;
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int els = 0;
  int right = len - 1;
  while (right >= 0) {
    if (arr[right] <= value) {
      break;
    }
    right--;
  }
  int left = 0;
  while (left < right) {
    int current = right;
    while (current > left) {
      if (arr[left] + arr[current] == value) {
        els += 1;
      }
      current--;
    }
    left++;
  }
  return els;
}

int findFirstOccurrence(int* arr, int low, int high, int value) {
  int first = -1;
  int start = low;
  int end = high;
  while (start <= end) {
    int middle = start + (end - start) / 2;
    if (arr[middle] < value) {
      start = middle + 1;
    } else {
      if (arr[middle] == value) {
        first = middle;
      }
      end = middle - 1;
    }
  }
  return first;
}

int findLastOccurrence(int* arr, int low, int high, int value) {
  int last = -1;
  int begin = low;
  int finish = high;
  while (begin <= finish) {
    int center = begin + (finish - begin) / 2;
    if (arr[center] > value) {
      finish = center - 1;
    } else {
      if (arr[center] == value) {
        last = center;
      }
      begin = center + 1;
    }
  }
  return last;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int index = 0;
  while (index < len) {
    int first = findFirstOccurrence(arr,
                                    index + 1,
                                    len - 1,
                                    value - arr[index]);
    int last = findLastOccurrence(arr, index + 1, len - 1, value - arr[index]);
    if (first != -1 && last != -1) {
      count += last - first + 1;
    }
    index++;
  }
  return count;
}
