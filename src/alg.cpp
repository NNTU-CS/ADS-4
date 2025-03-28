// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int parCnt = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        parCnt++;
      }
    }
  }
  return parCnt;
}
int countPairs2(int *arr, int len, int value) {
  int parcnt = 0;
  int kk = len - 1;
  while (kk > 0 && arr[kk] > value) {
    kk--;
  }
  for (int left = 0; left < len; left++) {
    for (int right = kk; right > left; right--) {
      if (arr[left] + arr[right] == value) {
        parcnt++;
      }
    }
  }
  return parcnt;
}
int binarySearch(int *array, int s, int fiin, int uka) {
  int beg = -1, fin = -1;
  int low = s, high = fiin;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] >= uka) {
      if (array[mid] == uka) {
        beg = mid;
      }
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (beg == -1) return 0;
  low = beg;
  high = fiin;
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] <= uka) {
      if (array[mid] == uka) {
        fin = mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return (fin - beg) + 1;
}

int countPairs3(int *arr, int len, int value) {
  int ppcnt = 0;
  for (int i = 0; i < len; ++i) {
    ppcnt += binarySearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return ppcnt;
}
