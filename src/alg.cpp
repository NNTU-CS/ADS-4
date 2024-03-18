// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int cent = left + (right - left) / 2;
        if (arr[cent] == value) {
            count++;
            int i = cent + 1;
            while (i < size && arr[i] == value) {
                count++;
                i++;
            }
            i = cent - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            return count;
        } else if (arr[cent] < value) {
            left = cent + 1;
        } else {
            right = cent - 1;
        }
    }
    return 0;
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  int k = 0;
  while (k < len) {
    int i = k + 1;
    while (i < len) {
      if ((arr[k] + arr[i]) == value) {
        count++;
      }
      i++;
    }
    k++;
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int k = len - 1;
  do {
    k = k - 1;
  } 
  while (arr[k] > value) {
    int i = 0;
    while (i < endl) {
      int j = endl;
        while (j > i) {
          if (arr[j] + arr[i] == value) {
            count++;
          }
          j--;
        }
        i++;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int k = 0;
  while (k < len) {
    int k1 = value - arr[k];
    count = count + cbinsearch(&arr[k + 1], len - k - 1, k1);
    k++;
  }
  return count;
}
