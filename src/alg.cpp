// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int l = 0, r = len - 1;
  int count = 0;
  while (arr[r] > value) {
    r--;
  }
  for (int i = 0; i < r; i++) {
    for (int j = r; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  if (count != 0) {
    return count;
  }
  return 0;
}

int cbinsearch(int* arr, int size, int value) {
    int count = 0, left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            count++;
            int temp = mid - 1;
            while (temp >= 0 && arr[temp] == value) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while (temp < size && arr[temp] == value) {
                count++;
                temp++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int key = value - arr[i];
    count += cbinsearch(&arr[i + 1], len - i - 1, key);
  }
  return count;
}
