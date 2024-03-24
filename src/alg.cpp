// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
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
  while (arr[right] > value) {
      right--;
  }
  for (int i = 0; i < right; i++) {
    for (int j = right; j > i; j--) {
      summa = arr[i] + arr[j];
      if (summa == value) {
        counter++;
      }
    }
  }
  if (counter == 0) {
    return 0;
  } else {
    return counter;
  }
}
int binarySearch(int *arr, int size, int value) {
  int counter = 0;
  int ind1 = 0;
  int ind2 = size - 1;
  int midle = 0;
  while (ind1 <= ind2) {
    int midle = ind1 + (ind2 - ind1) / 2;
    if (arr[midle] == value) {
      counter++;
      int left = midle - 1;
      while (left >= 0 && arr[left] == value) {
        counter++;
        left--;
      }
      int right = midle + 1;
      while (right < size && arr[right] == value) {
        counter++;
        right++;
      }
      return counter;
    } else if (arr[midle] < value) {
      ind1 = midle + 1;
    } else {
      ind2 = midle - 1;
    }
  }
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    counter += binarySearch(&arr[i + 1], len - i - 1, value - arr[i]); 
  }
  if (counter == 0) {
    return 0;
  } else {
    return counter;
  }
}
