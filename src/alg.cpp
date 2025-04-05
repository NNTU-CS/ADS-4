// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++counter;
      }
    }
  }
  return counter;
}

void MySort(int* arr, int len) {
  for (int i = 0; i < len - 1; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int countPairs2(int* arr, int len, int value) {
  MySort(arr, len);
  int result = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      ++result;
      ++left;
      --right;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }

  return result;
}

bool BinarySearch(int* arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return true;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

int countPairs3(int* arr, int len, int value) {
  MySort(arr, len);
  int count = 0;

  for (int i = 0; i < len - 1; ++i) {
    int complement = value - arr[i];
    if (BinarySearch(arr, i + 1, len - 1, complement)) {
      ++count;
    }
  }

  return count;
}
