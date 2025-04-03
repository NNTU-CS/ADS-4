// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        k++;
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  int l = 0;
  int r = len - 1;
  while (l < r) {
    if ((arr[l] + arr[r]) == value) {
      k++;
      l++;
      r--;
    } else if ((arr[l] + arr[r]) < value) {
      l++;
    } else {
      r--;
    }
  }
  return k;
}
bool binary(int* arr, int len, int target, int start) {
  int l = start + 1;
  int r = len - 1;
  while (l <= r) {
    int mid = l / 2 + r / 2;
    if (arr[mid] == target)
      return true;
    else if (arr[mid] > target)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return false;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len-1; i++) {
    int target = value - arr[i];
    if (binary(arr, len, target, i))
      k++;
  }
  return k;
}
