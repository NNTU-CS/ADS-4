// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j ++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
int count = 0;
while (arr[len] > value) {
  len--;
}
for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int key = 0;
  int left = 0;
  int right = len;
  int mid = 0;
  for (int i = 0; i < len; i ++) {
    key = value - arr[i];
    while (true) {
      mid = (right + left) / 2;
      if (arr[i] > mid) 
        left = mid;
      else if (arr[i] < mid)
        right = mid;
      else
        count ++;
        break;
    }
  }
  return count;
}
