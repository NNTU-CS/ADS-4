// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  if (count != 0)
    return count;
  else
    return 0;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len; j != i + 1; j--) {
      if (arr[i] + arr[j]) {
        count++;
      }
    }
  }
  if (count != 0)
    return count;
  else
    return 0;
}
int countPairs3(int *arr, int len, int value) {
  int key = 0;
  int count = 0;
  int left = 0;
  int right = len;
  int mid = 0;
  for (int i = 0; i < len; i++) {
    key = value - arr[i];
    while (true) {
      mid = (left + right) / 2;
      if (key < arr[mid])
        right = mid - 1;
      else if (key > arr [mid])
        left = mid + 1;
      else
        count ++;
      if (left > right)
        return -1;
    }
  }
  if (count != 0)
    return count;
  else
    return 0;
}
