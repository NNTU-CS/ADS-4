// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        counter++;
        break;
      }
    }
  }
  if (counter == 0) {
    return 0;
  } else {
    return counter;
  }
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  int summa = 0;
  while (left < right) {
    summa = arr[left] + arr[right];
    if (summa == value) {
      counter++;
      left++;
      right--;
    } else if (summa < value) {
      left++;
    } else {
      right--;
    }
  }
  if (counter == 0) {
    return 0;
  } else {
    return counter;
  }
}
bool binarySearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int middle = 0;
  while (left <= right) {
    middle = left + (right - left) / 2;
    if (arr[middle] == value) {
      return true;
    } else if (arr[middle] < value) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return false;    
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; ++i) {
    if (binarySearch(arr, len, value - arr[i])) {
      counter++;
    }
  }
  counter = counter / 2;
  if (counter == 0) {
    return 0;
  } else {
    return counter;
  }
}
