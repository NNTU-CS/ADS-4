// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int k12 = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i+1; j < len; j++) {
          if (arr[i] + arr[j] == value) {
              k12++;
          }
      }
  }
  if (k12 == 0)
  return k12;
return k12;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
    int k = 0;
    int end = len - 1;
    while (arr[end] > value) {
        end--;
    }
    for (int lefter = 0; lefter < end; lefter++) {
        for (int righter = end; lefter < righter; righter--) {
            if (arr[lefter] + arr[righter] == value) {
                k++;
            }
        }
    }
    if (k == 0)
        return 0;
    return k;
}
int binarySearch(int* arr, int el, int left, int right) {
  int k3 = 0;
  int mid = 0;
  int temp = 0;
  bool flag = false;
  int i;
  i = left - 1;
  while ((left <= right) && (flag != true)) {
      mid = (left + right) / 2;
      if (arr[mid] == el) {
          flag = true;
          temp = mid;
          k3++;
      }
      if (arr[mid] > el) {
          right = mid - 1;
      } else {
          left = mid + 1;
      }
  }
  while (arr[mid] == el) {
      mid++;
      if (arr[mid] == el) k3++;
  }
  mid = temp - 1;
  while ((arr[mid] == el) && (mid > i)) {
      if (arr[mid] == el) k3++;
      mid--;
  }
  return k3;
}
int countPairs3(int *arr, int len, int value) {
  int k3 = 0, i = 0, el;
  while (i < len) {
      el = value - arr[i];
      k3 += binarySearch(arr, el, i + 1, len - 1);
      i++;
  }
  return k3;
}
