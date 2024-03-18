// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i+1; j < len; j++) {
          if (arr[i] + arr[j] == value) {
              k++;
          }
      }
  }
  return k;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  std::sort(arr, arr + len);
  int left = 0;
  int right = len - 1;
  while (left < right) {
      if (arr[left] + arr[right] == value) {
          k++;
          left++;
          right--;
      } else if (arr[left] + arr[right] < value) {
          left++;
      } else {
          right--;
      }
  }
  return k;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  sort(arr, arr + len);
  for (int i = 0; i < len; i++) {
      int left = i + 1;
      int right = len - 1;
      while (left < right) {
          int sum = arr[i] + arr[left] + arr[right];
          if (sum == value) {
              k++;
              left++;
              right--;
          } else if (sum < value) {
              left++;
          } else {
              right--;
          }
      }
  }
  return k;
  return 0;
}
