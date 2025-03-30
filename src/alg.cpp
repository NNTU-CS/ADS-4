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
  int finall = len - 1;
  while (finall > 0) {
    if (arr[finall] > 0) {
      finall--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = finall; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count2++;
      }
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
  for (int i = 0; i < len; i++) {
    count3 += binarySecondSearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return count3;
}
