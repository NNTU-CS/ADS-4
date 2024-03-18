// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k1 = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i+1; j < len; j++) {
          if (arr[i] + arr[j] == value) {
              k1++;
          }
      }
  }
  return k1;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  int k2 = 0;
  for (int i = 0; i < len - 1; i++) {
      for (int j = 0; j < len - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
              int temp = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
          }
      }
  }
  for (int i = 0; i < len; i++) {
    int left = i + 1;
    int right = len - 1;
    while (left < right) {
        int summ = arr[i] + arr[left] + arr[right];
            if (summ == value) {
                k2++;
                left++;
                right--;
            } else if (summ < value) {
                left++;
            } else {
                right--;
            }
    }
  }
  return k2;
  return 0;
}
int binarySearch(int arr, int low, int jef, int har) {
  while (low <= jef) {
      int mid = low + (jef - low) / 2;
      if (arr[mid] == har) {
          return mid;
      } else if (arr[mid] < har) {
          low = mid + 1;
      } else {
          jef = mid - 1;
      }
  }
  return -1;
}
int countPairs3(int *arr, int len, int value) {
  int k3 = 0;
  for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
          if (arr[i] > arr[j]) {
              int temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
          }
      }
  }
  for (int i = 0; i < len; i++) {
      int target = value - arr[i];
      int index = binarySearch(arr, i+1, len-1, target);
      if (index != -1) {
          k3++;
      }
  }
  return k3;
  return 0;
}
