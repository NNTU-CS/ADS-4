// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int k = 0; k < len; k++) {
    for (int r = k + 1; r < len; r++) {
      if (arr[k] + arr[r] == value) {
        count++;
      }
    }
  }
  return count;
}

// Function to count pairs using improved sum search
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
    while (left < right) {
      if (arr[left] + arr[right] == value) {
        count++;
        left++;
        right--;
      } else if (arr[left] + arr[right] < value) {
        left++;
      } else {
        right--;
        }
    }
    return count;
}

// Function to count pairs using binary search for the second element
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int low = i + 1;
    int high = len - 1;
     while (low <= high) {
        int mid = low + (high - low) / 2;
          if (arr[mid] == target) {
            count++;
            break;
          } else if (arr[mid] < target) {
              low = mid + 1;
            } else {
               high = mid - 1;
            }
        }
    }
    return count;
}
