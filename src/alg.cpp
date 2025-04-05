// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    if (arr[left] + arr[right] == value) {
      counter++;
      left++;
      right--;
    } else if (arr[left] + arr[right] > value) {
      right--;
    } else {
      left++;
    }
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
}
