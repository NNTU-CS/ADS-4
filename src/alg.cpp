// Copyright 2021 NNTU-CS
void quickSort(int* arr, int left, int right) {
    if (left < right) {
      int povrt = arr[left + (right - left) / 2];
      int l = left;
      int r = right;
      while (l <= r) {
        while (arr[l] < povrt) {
          l++;
        }
        while (arr[r] > povrt) {
          r--;
        }
        if (l <= r) {
          int temp = arr[l];
          arr[l] = arr[r];
          arr[r] = temp;
          l++;
          r--;
        }
      }
      quickSort(arr, left, r);
      quickSort(arr, l, right);
    }
}

int countPairs1(int *arr, int len, int value) {
  quickSort(arr, 0, len - 1);
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cnt++;
      }
      if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return cnt;
}

int countPairs2(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int cnt = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int summa = arr[left] + arr[right];
        if (summa == value) {
            cnt++;
            int l = arr[left];
            int r = arr[right];
            while (left < right && arr[left] == l) {
                left++;
            }
            while (left < right && arr[right] == r) {
                right--;
            }
        } else if (summa < value) {
            left++;
        } else {
            right--;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int cnt = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int summa = arr[left] + arr[right];
        if (summa == value) {
            cnt++;
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1]) {
                left++;
            }
            while (left < right && arr[right] == arr[right + 1]) {
                right--;
            }
        } else if (summa < value) {
            left++;
        } else {
            right--;
        }
    }
    return cnt;
}
