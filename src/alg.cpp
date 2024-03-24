// Copyright 2021 NNTU-CS
int countPairs1(int * arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }

  return count;
}
int countPairs2(int * arr, int len, int value) {
  int count = 0;
  int right = len - 1;

  while (arr[right] > value) {
    right--;
  }

  for (int left = 0; left < right; left++) {
    for (int r = right; r > left; r--) {
      if (arr[left] + arr[r] == value) {
        count++;
      }
    }
  }

  return count;
}
int countPairs3(int * arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    int left = i + 1;
    int right = len - 1;
    int target = value - arr[i];

    while (left <= right) {
      int middle = (left + right) / 2;

      if (arr[middle] == target) {
        count++;
        int tempMiddle = middle - 1;

        while (tempMiddle > i && arr[tempMiddle] == target) {
          count++;
          tempMiddle--;
        }

        tempMiddle = middle + 1;

        while (tempMiddle < len - 1 && arr[tempMiddle] == target) {
          count++;
          tempMiddle++;
        }

        break;
      } else if (arr[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  }

  return count;
}
