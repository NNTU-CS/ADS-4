// Copyright 2021 NNTU-CS
#include <unistd.h>
int binfound(int* arr, int size, int x) {
    int l = 0, r = size - 1, count = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            count++;
            int i = mid-1;
            while (i >= 0 && arr[i] == x) {
                count++;
                i--;
            }
            i = mid +1;
            while (i < size && arr[i] == x) {
                count++;
                i++;
            }
            return count;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return 0;
}

int countPairs1(int* arr, int len, int value) {
    sleep(10);
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right--;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    int ind = 0;
    for (int i = 0; i < len; i++) {
        ind = value - arr[i];
        count += binfound(&arr[i+1], len - i, ind);
    }
    return count;
}
