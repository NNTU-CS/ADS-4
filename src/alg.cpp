// Copyright 2021 NNTU-CS
void quickSort(int* arr, int low, int high) {
  if (low < high) {
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
    int pivotIndex = i + 1;

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

void sortArray(int* arr, int len) { quickSort(arr, 0, len - 1); }

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  sortArray(arr, len);
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  sortArray(arr, len);
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum < value) {
      left++;
    } else if (sum > value) {
      right--;
    } else {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftVal = arr[left], rightVal = arr[right];
      int leftCount = 0, rightCount = 0;
      while (left < len && arr[left] == leftVal) {
        leftCount++;
        left++;
      }
      while (right >= 0 && arr[right] == rightVal) {
        rightCount++;
        right--;
      }
      count += leftCount * rightCount;
    }
  }
  return count;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  sortArray(arr, len);
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int low = i + 1;
    int high = len - 1;
    int fountIndex = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] < target) {
        low = mid + 1;
      } else if (arr[mid] > target) {
        high = mid - 1;
      } else {
        fountIndex = mid;
        break;
      }
    }
    if (fountIndex != -1) {
      int countLocal = 1;
      int j = fountIndex - 1;
      while (j >= i + 1 && arr[j] == target) {
        countLocal++;
        j--;
      }
      j = fountIndex + 1;
      while (j < len && arr[j] == target) {
        countLocal++;
        j++;
      }
      count += countLocal;
    }
  }
  return count;
}
