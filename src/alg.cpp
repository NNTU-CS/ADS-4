// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i)
    for (int j = i + 1; j < len; ++j)
      if (arr[i] + arr[j] == value) count++;
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int numElements = right - left + 1;
        count += (numElements * (numElements - 1)) /
                 2;
        break;
      } else {
        int countLeft = 1;
        int countRight = 1;
        while (left + 1 < right && arr[left] == arr[left + 1]) {
          countLeft++;
          left++;
        }
        while (right - 1 > left && arr[right] == arr[right - 1]) {
          countRight++;
          right--;
        }
        count += countLeft * countRight;
        left++;
        right--;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        int l = mid - 1;
        while (l >= left && arr[i] + arr[l] == value) {
          count++;
          l--;
        }
        int r = mid + 1;
        while (r <= right && arr[i] + arr[r] == value) {
          count++;
          r++;
        }
        break;
      } else if (arr[i] + arr[mid] < value) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
