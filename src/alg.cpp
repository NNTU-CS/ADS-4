// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int perem = len - 1;
  while (arr[perem] > value) {
    perem--;
  }
  int count = 0;
  for (int i = 0; i < perem; i++) {
    for (int j = perem; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        count++;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  int right, mid1, mid2, left;
  for (int i = 0; i < len; ++i) {
    right = len - 1;
    left = i + 1;
    mid2 = value - arr[i];
    while (left <= right) {
      mid1 = (left + right) / 2;
      if (arr[mid1] == mid2) {
        counter++;
        int next = mid1 - 1;
        while ((next > i) && (arr[next] == arr[mid1])) {
          counter++;
          next--;
        }
        int next2 = mid1 + 1;
        while ((i < next2) && (arr[next2] == arr[mid1])) {
          counter++;
          next2++;
        }
        break;
      } else if (arr[mid1] > mid2) {
        right = mid1 - 1;
      } else {
        left = mid1 + 1;
      }
    }
  }
  return counter;
}
