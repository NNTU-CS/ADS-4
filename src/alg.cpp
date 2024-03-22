// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int endl = len - 1;
  while (arr[endl] > value) endl--;
  for (int i = 0; i < endl; i++) {
    for (int j = endl; i < j; j--) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  int per1, mid1, mid2, per2;
  for (int i = 0; i < len; ++i) {
    per1 = len - 1;
    per2 = i + 1;
    mid2 = value - arr[i];
    while (per2 <= per1) {
      mid1 = (per2 + per1) / 2;
      if (arr[mid1] == mid2) {
        count++;
        int next = mid1 - 1;
        while ((next > i) && (arr[next] == arr[mid1])) {
          count++;
          next--;
        }
        int next2 = mid1 + 1;
        while ((i < next2) && (arr[next2] == arr[mid1])) {
          count++;
          next2++;
        }
        break;
      } else if (arr[mid1] > mid2) {
        per1 = mid1 - 1;
      } else {
        per2 = mid1 + 1;
      }
    }
  }
  return count;
}
