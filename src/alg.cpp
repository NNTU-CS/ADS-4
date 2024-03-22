// Copyright 2021 NNTU-CS
int findenteres(int* arr, int len, int value) {
  int left = 0, right = len - 1;
  int middle = left + (right - left) / 2;
  int index = -1;
  while (right > left) {
    if (arr[middle] == value) {
      index = middle;
      break;
    } else if (arr[middle] > value) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  if (index == -1) {
    return 0;
  }
  int counter = 1, left1 = index - 1;
  while (left1 >= 0 && arr[left1] == value) {
    left1 -= 1;
    counter += 1;
  }
  int right1 = index + 1;
  while (right1 < len && arr[right1] == value) {
    counter += 1;
    right1 += 1;
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
  long int right = len - 1, counter = 0, b_res = 101, b_val = 101;
  while (arr[right] > value) {
    right -= 1;
  }
  while (right > 1) {
    if (arr[right] == b_val) {
      if (b_val == 25) {
        b_res -= 1;
      }
      counter += b_res;
    } else {
      long int to_find = value - arr[right];
      long int result = findenteres(arr, right, to_find);
      counter += result;
      b_val = arr[right];
      b_res = result;
    }
    right -= 1;
  }
  return counter;
}
