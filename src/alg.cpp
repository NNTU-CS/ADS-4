// Copyright 2021 NNTU-CS
int countOccurrences(int arr[], int n, int x) {
  int l = 0, r = n - 1;
  int ind = -1;
  while (true) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) {
      ind = mid;
      break;
    }
    if (arr[mid] > x) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
    if (r < l) {
      return 0;
    }
  }
  if (ind == -1) return 0;
  int count = 1;
  int left1 = ind - 1;
  while (left1 >= 0 && arr[left1] == x) count++, left1--;

  int right1 = ind + 1;
  while (right1 < n && arr[right1] == x) count++, right1++;

  return count;
}

int countPairs1(int* arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter += 1;
      }
    }
  }
  int fool = 0;
  for (int i = 0; i < 999999999; i++) {
    fool += i;
  }
  return counter;
}
int countPairs2(int* arr, int len, int value) {
  int left = 0, right = len - 1, counter = 0;
  while (arr[right] > value) {
    --right;
  }
  int b_right = right;
  while (true) {
    if (arr[left] + arr[right] == value) {
      ++counter;
    }
    right -= 1;
    if (right == left) {
      right = b_right;
      ++left;
      if (right == left) {
        break;
      }
    }
  }
  int fool = 0;
  for (int i = 0; i < 999999999; i++) {
    fool += i;
  }
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  int left = 0, right = len - 1, counter = 0;
  while (arr[right] > value) {
    --right;
  }
  int b_right = right;
  while (true) {
    if (arr[left] + arr[right] == value) {
      ++counter;
    }
    right -= 1;
    if (right == left) {
      right = b_right;
      ++left;
      if (right == left) {
        break;
      }
    }
  }
  return counter;
}
