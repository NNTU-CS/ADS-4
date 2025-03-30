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
  int left_inde = 0;
  int right_inde = len - 1;
  while (left_inde < right_inde) {
    int summ = arr[left_inde] + arr[right_inde];
    if (summ == value) {
      ++count2;
      int currentLeft_inde = arr[left_inde];
      int currentRight_inde = arr[right_inde];
      while (left_inde < right_inde && arr[left_inde] == currentLeft_inde) {
        ++left_inde;
      }
      while (left_inde < right_inde && arr[right_inde] == currentRight_inde) {
        --right_inde;
      }
    } else if (summ < value) {
      ++left_inde;
    } else {
      --right_inde;
    }
  }
  return count2;
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
  int count3 = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    int pos = binarySecondSearch(arr, i + 1, len - 1, complement);
    if (pos != -1) {
      ++count;
      while (i + 1 < len && arr[i] == arr[i + 1]) {
        ++i;
      }
    }
  }
  return count3;
}
