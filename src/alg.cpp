// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >=0 && arr[j] >= 0)) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while (arr[right] > value) {
    right--;
  }
  for (int i =0; i < right; i++) {
    for (int j = right; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >=0 && arr[j] >= 0)) {
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
  for (int i = 0; i < len - 1; i++) {
    int leftBound = i;
    int rightBound = len;
    while (leftBound < rightBound - 1) {
      int center = (rightBound + leftBound) / 2;
      if (arr[i] + arr[center] == value) {
        counter++;
        int t = center + 1;
        while ((arr[i] + arr[j] == value) && (t < rightBound)) {
          counter++;
          t++;
        }
        t = center - 1;
        while ((arr[i] + arr[j] == value) && (t > leftBound)) {
          counter++;
          t--;
        }
        break;
      } else if (arr[i] + arr[center] > value) {
        rightBound = center;
      } else {
        leftBound = center;
      }
    }
  }
  return counter;
}
