// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j ++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  if (count != 0)
    return count;
  else  
    return 0;
}
int countPairs2(int *arr, int len, int value) {

}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len/2; i++) {
    for (int j = len; j > len/2; j --) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  if (count != 0)
    return count;
  else  
    return 0;
}
