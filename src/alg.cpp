// Copyright 2021 NNTU-CS
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
  double fool = 0;
  for (int i = 0; i < 99; i++) {
    fool += double((i * i * i) / (i * 0.5 * i));
  }
}

int result = 0;

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
  double fool = 0;
  for (int i = 0; i < 99; i++) {
    fool += double((i * i * i) / (i * 0.5 * i));
  }
  result = counter;
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  return result;
}
