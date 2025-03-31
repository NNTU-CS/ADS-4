// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value)
        cnt++;
  return cnt;
}
int countPairs2(int* arr, int len, int value) {
  if (arr[len -1] + arr[len - 2] < value)
    return 0;
  int cnt = 0;
  int temp = len - 1;
  for (int i = 0; i < temp; i++) {
    while (arr[i] + arr[temp] > value)
      temp--;
    if (arr[i] + arr[temp] < value)
      continue;
    for (int j = i; j < temp; j++)
      if (arr[j] + arr[temp] == value)
        cnt++;
  }
  return cnt;
}
int bSearch(int* arr, const int value, int l, int h) {
  int low = l;
  int high = h;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (value == arr[mid])
      return mid;
    if (value > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return 0;
}
int countPairs3(int* arr, int len, int value) {
  if (arr[len - 1] + arr[len - 2] < value)
    return 0;
  int cnt = 0;
  int temp = len - 1;
  for (int i = 0; i < temp; i++) {
    while (arr[i] + arr[temp] > value)
      temp--;
    if (arr[i] + arr[temp] < value)
      continue;
    int fIndex = bSearch(arr, value - arr[i], i, temp);
    if (fIndex) {
      cnt++;
      if (arr[fIndex - 1] == value - arr[i])
        for (int j = 1; fIndex - j > i; j++) {
          if (arr[fIndex - j] == value - arr[i])
            cnt++;
          else
            break;
        }
      
      if (arr[fIndex + 1] == value - arr[i])
        for (int j = 1; j <= temp - fIndex; j++) {
          if (arr[fIndex + j] == value - arr[i])
            cnt++;
          else
            break;
        }
    }
  }
  if (!cnt)
    return cnt;
  else
    return cnt - 1;
}
