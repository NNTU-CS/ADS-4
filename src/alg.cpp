// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int k = 0; k < len - 1; k++) {
    for (int r = k + 1; r < len; r++) {
      if ((arr[k] + arr[r]) == value) {
             count++;
       }
      }
    }
       return count;
}

int countPairs2(int* arr, int len, int value) {
    int left = 0;
    int count = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right--;
    }
for (int k = 0; k < right; k++) {
        for (int r = right; r > i; r--) {
            int summa = arr[k] + arr[r];
            if (summa == value) {
              count++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  return 0;

int binarysearch(int* arr, int size, int value) {
    int right = size - 1;
    int count = 0;
    int left = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == value) {
            count++;
            int left = middle - 1;
            int right = middle + 1;
            while (left >= 0 && arr[left] == value) {
             count++;
                left--;
            }
            while (right < size && arr[right] == value) {
                count++;
                right++;
            }
            return count;
        }
        if (arr[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int k = 0; k < len; k++) {
        int second = value - arr[k];
        count += binarysearch(&arr[k + 1], len - (k - 1), second);
    }
    return count;
}
