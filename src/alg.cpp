// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count= 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            }
        }
    }
    return count;
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int right, m1, m2, left;
  for (int i = 0; i < len; ++i) {
    right = len - 1;
    left = i + 1;
    m2 = value - arr[i];
    while (left <= right) {
      mid1 = (left + right) / 2;
      if (arr[m1] == m2) {
        count++;
        int next = m1 - 1;
        while ((next > i) && (arr[next] == arr[m1])) {
          count++;
          next--;
        }
        int next2 = m1 + 1;
        while ((i < next2) && (arr[next2] == arr[m1])) {
          count++;
          next2++;
        }
        break;
      } else if (arr[m1] > m2) {
        right = m1 - 1;
      } else {
        left = m1 + 1;
      }
    }
  }
  return count;
}
