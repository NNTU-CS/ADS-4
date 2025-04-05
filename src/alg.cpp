// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i]+arr[j] == value) count++;
    }
  }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int high = len - 1;
  while(high > 0) {
      if (arr[high] + arr[0] > value){
          high --;
      }
      else break;
  }
  for (int i = 0; i < len; i++) {
      for (int j = high; j > i; j--) {
          if (arr[i]+arr[j] == value) count++;
      }
  }
  return count;
}
int binSearch(int *arr,int left, int right, int value) {
  int mid;
  while (left <= right) {
      mid = left + (right - left)/2;
      if (arr[mid] == value) return mid;
      if (arr[mid] > value) right = mid - 1;
      if (arr[mid] < value) left = mid + 1;
  }
  return -1;
}
int countPairs3(int *arr, int len, int value) {
  int countAll = 0;
  for (int i = 0; i < len; i++) {
    int item = value - arr[i];
    int ndx = binSearch(arr, i+1, len-1, item);
    if (ndx != -1 && arr[i]+ item == value) {
        int count = 1;
        int left = ndx - 1;
        while (left >= 0 && arr[left] == item) {
            count++;
            left--;
        }
        int right = ndx + 1;
        while (right < len && arr[right] == item) {
            count++;
            right++;
        }
        countAll += count;
    }
  }
  return countAll;
}
