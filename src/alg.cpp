// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
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
  int temp;
  int left = 0;
  int right = len-1;
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      temp = right-1;
      while ((left < temp) && (arr[left] + arr[temp] == value)) {
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
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int complement = value - arr[i];
    for (int j = i + 1; j < len; j++) {
      if (arr[j] == complement) {
        count++;
        while ((j + 1 < len) && (arr[j] == arr[j + 1])) {
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
