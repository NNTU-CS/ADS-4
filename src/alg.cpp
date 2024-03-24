// Copyright 2021 NNTU-CS
int findFirstGreaterThan(int* arr, int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] > value) {
      return i;
    }
  }
  return 0;
}
int binarySearch(int* arr, int size, int value) {
  int found = 0;
  int first = 0;
  int last = size - 1;
  int middle = 0;
  while (first <= last) {
    middle = (first + last) / 2;
    if (arr[middle] == value) {
      ++found;
      int index = middle - 1;
      while (index >= first && arr[index] == value) {
        ++found;
        --index;
      }
      index = middle + 1;
      while (index <= last && arr[index] == value) {
        ++found;
        ++index;
      }
      return found;
    } else if (arr[middle] < value) {
      first = middle + 1;
    } else {
      last = middle - 1;
    }
  }
  return 0;
}
int countPairs1(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (value == arr[i] + arr[j]) {
        ++result;
      }
    }
  }
  return result;
}
int countPairs2(int *arr, int len, int value) {
  int result = 0;
  len = findFirstGreaterThan(arr, len, value);
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (value == arr[i] + arr[j]) {
        ++result;
      }
    }
  }
  return result;
}
int countPairs3(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len; ++i) {
    int n = value - arr[i];
    result += binarySearch(arr + i + 1, len - i - 1, n);
  }
  return result;
}
