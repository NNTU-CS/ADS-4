// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int left, int right, int value) {
  int middle = left + (right - left) / 2;
  if (right < left) {
    return -1;
  }
  if (arr[middle] == value) {
    return middle;
  }
  if (arr[left] == value) {
    return left;
  }
  if (arr[right] == value) {
    return right;
  }
  if (arr[middle] > value) {
    return cbinsearch(arr, left, middle - 1, value);
  } else {
    return cbinsearch(arr, middle + 1, right, value);
  }
}

int findenteres(int* arr, int len, int value) {
  int index = cbinsearch(arr, 0, len - 1, value);
  if (index == -1) {
    return 0;
  }
  int counter = 1, left = index - 1;
  while (left >= 0 && arr[left] == value) {
    left -= 1;
    counter += 1;
  }
  int right = index + 1;
  while (right < len && arr[right] == value) {
    counter += 1;
    right += 1;
  }
  return counter;
}

int countPairs1(int* arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter += 1;
      }
    }
  }
  return counter;
}
int countPairs2(int* arr, int len, int value) {
  int left = 0, right = len - 1, counter = 0;
  while (arr[right] > value) {
    --right;
  }
  int b_right = right;
  while (true) {
    if (arr[left] + arr[right] == value) {
      ++counter;
    }
    right -= 1;
    if (right == left) {
      right = b_right;
      ++left;
      if (right == left) {
        break;
      }
    }
  }
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  int right = len - 1, counter = 0;
  while (arr[right] > value) {
    right -= 1;
  }
  while (right > 1) {
    int to_find = value - arr[right];
    int result = findenteres(arr, right, to_find);
    counter += result;
    right -= 1;
  }
  return counter;
}
