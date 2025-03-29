// Copyright 2021 NNTU-CS
void insertionSort(int* arr, int len) {
  for (int i = 1; i < len; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
int countPairs1(int *arr, int len, int value) {
  insertionSort(arr, len);
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if ((i != j) && (arr[i] + arr[j] == value)) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  insertionSort(arr, len);
  int temp;
  int left = 0;
  int right = len-1;
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      temp = right-1;
      while (arr[left] + arr[temp] == value) {
        count++;
        temp--;
      }
      left++;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  insertionSort(arr, len);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int complement = value - arr[i];
    for (int j = i + 1; j < len; j++) {
      if (arr[j] == complement) {
        count++;
        while (j + 1 < len && arr[j] == arr[j + 1]) {
          j++;
          count++;
        }
      }
      if (arr[j] > complement) {
        break;
      }
    }
  }
  return count;
}
