// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count1;
        break;
      }
    }
  }
  return count1;
}

int countPairs2(int *arr, int len, int value) {
  int count2 = 0;
  int up = len - 1;
  while (up > 0 && arr[up] > value) {
    up--;
  }
  for (int current = 0; current < len; current++) {
    for (int reversed = up; reversed > current; reversed--) {
      if (arr[current] + arr[reversed] == value) {
        count2++;
      }
    }
  }
  return count2;
}

int binarySecondSearch(int *arr, int left_inde, int right_inde, int target) {
  int start = -1;
  int low = left_inde;
  int high = right_inde;
  while (low <= high) {
    int mid_inde = low + (high - low) / 2;
    if (array[mid_inde] >= target) {
      high = mid_inde - 1;
      if (array[mid_inde] == target) start = mid_inde;
    } else {
      low = mid_inde + 1;
    }
  }
  if (start == -1) {
    return 0;
  }
  int end = start;
  low = start;
  high = right_inde;
  while (low <= high) {
    int mid_inde = low + (high - low) / 2;
    if (array[mid_inde] <= target) {
      low = mid_inde + 1;
      if (array[mid_inde] == target) end = mid_inde;
    } else {
      high = mid_inde - 1;
    }
  }
  return end - start + 1;
}

int countPairs3(int *arr, int len, int value) {
  int count3 = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    int pos = binarySecondSearch(arr, i + 1, len - 1, complement);
    if (pos != -1) {
      ++count3;
      while (i + 1 < len && arr[i] == arr[i + 1]) {
        ++i;
      }
    }
  }
  return count3;
}
