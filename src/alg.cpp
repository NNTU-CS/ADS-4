// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for(int i = 0; i < len - 1; i++) {
    for(int j = i; j < len; j++) {
      if(arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
}
