// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        kol++;
      }
    }
  }
  return kol;
}

int countPairs2(int *arr, int len, int value) {
  int kol = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int count = right - left + 1;
        kol += count * (count - 1) / 2; 
        break;
      }
      int leftCount = 1, rightCount = 1;
      while (left + 1 < right && arr[left] == arr[left + 1]) {
        leftCount++;
        left++;
      }
      while (left < right - 1 && arr[right] == arr[right - 1]) {
        rightCount++;
        right--;
      }
      kol += leftCount * rightCount;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return kol;
}

int countPairs3(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; i++) {
    int vtor = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] == vtor) {
        kol++;
        int temp = middle - 1;
        while (temp >= left && arr[temp] == vtor) {
          kol++;
          temp--;
        }
        temp = middle + 1;
        while (temp <= right && arr[temp] == vtor) {
          kol++;
          temp++;
        }
        break;
      } else if (arr[middle] < vtor) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  }
  return kol;
}
