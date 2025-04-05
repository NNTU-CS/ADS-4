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
  while (high > 0) {
      if (arr[high] + arr[0] > value) {
          high--;
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
  while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == value) return mid;
      if (arr[mid] > value) right = mid - 1;
      if (arr[mid] < value) left = mid + 1;
  }
  return -1;
}
int countPairs3(int *arr, int len, int value) {
  int countAll = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] > value / 2) continue;
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int item = value - arr[i];
    int ndx = binSearch(arr, i + 1, len - 1, item);
    if (ndx != -1) {
        if(arr[i] == item) {
          int count = 1;
          int j = i + 1;
          while (j < len && arr[j] == arr[i]) {
            count++;
            j++;
          }
          int count_itm = 1;
          j = ndx + 1;
          while (j < len && arr[i] == item){
            count_itm++;
            j++;
          } 
          if (count > 1) countAll += count * (count - 1) / 2;                
          } else if (arr[i] < item) {
              int count_i = 1;
              int j = i + 1;
              while(j < len && arr[j] == arr[i]) {
                count_i++;
                j++;
              }
              int count_itm = 1;
              j = ndx + 1;
              while(j < len && arr[j] == item) {
                count_itm++;
                j++;
              }
              countAll += count_i * count_itm;
          }
      }
  }
return countAll;
}
