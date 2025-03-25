// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
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
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
  {
      for (int j = len - 1; j > i; j--) {
          if (arr[i] + arr[j] == value) {
              count++;
          }
      }
  }
  return count;
}

int binarySearchLower(int* arr, int low, int high, int key) {
  int ans = -1;
  while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == key) {
          ans = mid;
          high = mid - 1;
      } else if (arr[mid] < key) {
          low = mid + 1;
      } else {
          high = mid - 1;
      }
  }
  return ans;
}

int binarySearchUpper(int* arr, int low, int high, int key) {
  int ans = -1;
  while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == key) {
          ans = mid;
          low = mid + 1;
      } else if (arr[mid] < key) {
          low = mid + 1;
      } else {
          high = mid - 1;
      }
  }
  return ans;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
      int target = value - arr[i];
      int lower = binarySearchLower(arr, i + 1, len - 1, target);
      if (lower != -1) {
          int upper = binarySearchUpper(arr, i + 1, len - 1, target);
          count += (upper - lower + 1);
      }
  }
  return count;
}
