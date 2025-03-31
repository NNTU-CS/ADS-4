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
    for (int j = i; j <= temp;) {
        if (arr[++j] + arr[i] == value)
            cnt++;
        if (arr[j] + arr[i] > value)
            break;
    }
  }
  return cnt;
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
    int low = i + 1, high = temp, target = value - arr[i];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            cnt++;
            int current = mid;
            while (++current <= temp && arr[current] == target)
              cnt++;
            current = mid;
            while (--current > i && arr[current] == target)
                cnt++;
            break;
        }
        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
  }
  return cnt;
}
