// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
  int l = 0;
  int r = size - 1;
  int mid = (r + l) / 2;
  int counter = -1;
  while (l <= r) {
    if (arr[mid] == value) {
      counter += 2;
      break;
    }
    if (arr[mid] > value)
      r = mid - 1;
    else
      l = mid + 1;
    mid = (r + l) / 2;
  }
  if (counter == -1) return 0;
  for (int i = mid - 1; i >= 0; i--) {
    if (arr[i] == value)
      counter++;
    else
      break;
  }
  for (int i = mid + 1; i <= size - 1; i++) {
    if (arr[i] == value)
      counter++;
    else
      break;
  }
  return counter;
}

int countPairs1(int* arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) counter++;
    }
  }
  return counter;
}

int countPairs2(int* arr, int len, int value) {
  int counter = 0;
  int max = len - 1;
  while (arr[max] > value) max--;
  for (int i = 0; i <= max; i++) {
    for (int j = i + 1; j <= max; j++) {
      if (arr[i] + arr[j] == value) counter++;
    }
  }
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  int counter = 0;
  int max = len - 1;
  while (arr[max] > value) max--;
  for (int i = 0; i <= max; i++) {
    counter += cbinsearch(arr + i + 1, max - i, value - arr[i]);
  }
  return counter;
}
