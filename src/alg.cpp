// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
        break;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left_inde = 0;
  int right_inde = len - 1;
  while (left_inde < right_inde) {
    int summ = arr[left_inde] + arr[right_inde];
    if (summ == value) {
      ++count;
      ++left_inde;
      --right_inde;
    } else if (summ < value) {
      ++left_inde;
    } else {
      --right_inde;
    }
  }
  return count;
}

int binarySecondSearch(int *arr, int left_inde, int right_inde, int target) {
  while (left_inde <= right_inde) {
    int mid_inde = left_inde + (right_inde - left_inde) / 2;
    if (arr[mid_inde] == target) {
      return mid_inde;
    } else if (arr[mid_inde] < target) {
      left_inde = mid_inde + 1;
    } else {
      right_inde = mid_inde - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    if (binarySecondSearch(arr, i + 1, len - 1, complement) != -1) {
      ++count;
    }
  }
  return count;
}

