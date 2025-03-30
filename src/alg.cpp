// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count1;
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
      if (arr[left_inde] == arr[right_inde]) {
        int num = right_inde - left_inde + 1;
        count2 += num * (num - 1) / 2;
        break;
      }
      int currentLeft_inde = arr[left_inde];
      int currentRight_inde = arr[right_inde];
      int left_count = 0;
      int right_count = 0;
      while (arr[left_inde] == currentLeft_inde) {
        left_inde++;
        left_count++;
      }
      while (arr[right_inde] == currentRight_inde) {
        right_inde--;
        right_count++;
      }
      count2 += left_count * right_count;
    } else if (summ < value) {
      left_inde++;
    } else {
      right_inde--;
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
  for (int i = 0; i < len - 1; ++i) {
    int complement = value - arr[i];
    int pos = binarySecondSearch(arr, i + 1, len - 1, complement);
    if (pos != -1) {
      ++count3;
      int left_inde = pos - 1;
      while (left_inde > i && arr[left_inde] == complement) {
        ++count3;
        --left_inde;
      }
      int right_inde = pos + 1;
      while (right_inde < len && arr[right_inde] == complement) {
        ++count3;
        ++right_inde;
      }
    }
  }
  return count3;
}
