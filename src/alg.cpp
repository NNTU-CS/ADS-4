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
      } else {
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

int binarySearch(int* arr, int len, int target) {
  int left = 0;
  int right = len - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    for (int j = i + 1; j < len; j++) {
      if (arr[j] == complement) {
        count++;
      }
    }
  }
  return count;
}
