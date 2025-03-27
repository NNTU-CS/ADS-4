// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)cnt++;
    }
  }
  return cnt;
}
int countPairs2(int *arr, int len, int value) {
  int cnt = 0;
  int trr = len - 1;
  while (trr > 0) {
    if (arr[trr] > value) {
      trr--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = trr; j > i; j--) {
      if (arr[i] + arr[j] == value) cnt++;
    }
  }
  return cnt;
}
int binary(int *arr, int low, int high, int value) {
  int begin = -1;
  int led = low, rig = high;
  while (led <= rig) {
    int mid = led + (rig - led) / 2;
    if (arr[mid] >= value) {
      rig = mid - 1;
      if (arr[mid] == value) begin = mid;
    } else {
      led = mid + 1;
    }
  }
  if (begin == -1) return 0;
  int fin = begin;
  led = begin;
  rig = high;
  while (led <= rig) {
    int mid = led + (rig - led) / 2;
    if (arr[mid] <= value) {
      led = mid + 1;
      if (arr[mid] == value) fin = mid;
    } else {
      rig = mid - 1;
    }
  }
  return fin - begin + 1;
}
int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    cnt += binary(arr, i + 1, len - 1, value - arr[i]);
  }
  return cnt;
}
