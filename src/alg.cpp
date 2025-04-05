// Copyright 2021 NNTU-CS
int partition(int * arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int countPairs1(int *arr, int len, int value) {
  quickSort(arr, 0, len - 1);
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (!(arr[j - 1] == arr[j])) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  quickSort(arr, 0, len - 1);
  int left = 0;
  int right = len - 1;
  int count = 0;
  while (left < right) {
    int currentSum = arr[left] + arr[right];
    if (currentSum == value) {
      count++;
      left++;
      right--;
        for (int i = 0; i < len; i++) {
          if (right != i) {
            if (arr[i] == arr[right]) {
              count++;
            }
          }
        }
    } else if (currentSum < value) {
        left++;
    } else {
        right--;
    }
  }
  return count;
}
int binarySearch(int arr[], int left, int right, int target) {
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
int countPairs3(int arr[], int len, int value) {
  quickSort(arr, 0, len - 1);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int complement = value - arr[i];
    int index = binarySearch(arr, i + 1, len - 1, complement);
    if (index != -1) {
      count++;
      while (index + 1 < len && arr[index + 1] == complement) {
        count++;
        index++;
      }
    }
  }
  return count;
}
