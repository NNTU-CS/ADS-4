// Copyright 2024 NNTU-CS
int countPairs1(int* arr, int kol, int val) {
  int q = 0;
  for (int i = 0; i < kol; i++) {
    for (int j = i + 1; j < kol; j++) {
      if (arr[i] + arr[j] == val) {
        q++;
      }
    }
  }
  return q;
}

int countPairs2(int* arr, int kol, int val) {
  int q = 0, pos = kol - 1;
  for (int i = kol; i > 0; --i) {
    if (arr[i] > val) {
      pos = i;
    }
  }
  for (int i = 0; i < pos; ++i) {
    for (int j = pos; j > i; --j) {
      if (arr[i] + arr[j] == val) {
        q++;
      }
    }
  }
  return q;
}

int countPairs3(int* arr, int kol, int val) {
  int q = 0;
  for (int i = 0; i < kol - 1; i++) {
    int left = i;
    int right = kol;
    while (left < right - 1) {
      int mid = (right + left) / 2;
      if (arr[i] + arr[mid] == val) {
        q++;
        int j = mid + 1;
        while ((arr[i] + arr[j] == val) && (j < right)) {
          q++;
          j++;
        }
      }
      if (arr[i] + arr[mid] < val) {
        left = mid;
      } else {
        right = mid;
      }
    }
  }
  return q;
}
