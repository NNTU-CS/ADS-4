// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left <= right) {
    int currentSum = arr[left] + arr[right];
    if (currentSum == value) {
      if (arr[left] == arr[right]) {
        int totalElements = right - left + 1;
        count += (totalElements * (totalElements - 1)) / 2;
        break;
      }
      else {
        int countLeft = 1;
        int countRight = 1;
        while (left + 1 <= right && arr[left] == arr[left + 1]) {
          countLeft++;
          left++;
        }
        while (right - 1 >= left && arr[right] == arr[right - 1]) {
          countRight++;
          right--;
        }
        count += countLeft * countRight;
      }
      left++;
      right--;
    } else if (currentSum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int left = 0;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int j = mid;
        while (j < len && arr[j] == target) {
          j++;
        }
        count += j - mid;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1]) {
      i++;
    }
  }
  return count;
}
