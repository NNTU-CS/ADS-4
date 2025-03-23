// Copyright 2021 NNTU-CS
int findParis(int* arr, int value, int n, int l, int r) {
  int count = 0;
  int middle = (l + r) / 2;

  if (r < l) {
    return 0;
  } else if (n + arr[middle] == value) {
    count++;
    int l_indx = -1;
    int r_indx = -1;

    if (middle != l) {
      l_indx = middle - 1;
    }

    if (middle != r) {
      r_indx = middle + 1;
    }

    while (l_indx >= l && arr[l_indx] + n == value) {
      count++;
      l_indx--;
    }

    while (r_indx <= r && arr[r_indx] + n == value) {
      count++;
      r_indx++;
    }

    return count;
  } else {
    return findParis(arr, value, n, middle + 1, r);
  }
}

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }

  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int l_indx = 0;
  int r_indx = len - 1;
  while (arr[r_indx] > value && r_indx != l_indx) {
    r_indx--;
  }

  while (arr[l_indx] + arr[r_indx] < value && l_indx != r_indx) {
    l_indx++;
  }

  for (int i = l_indx; i < r_indx; ++i) {
    for (int j = i + 1; j <= r_indx; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }

  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len - 1; ++i) {
    count += findParis(arr, value, arr[i], 0, len - 1);
  }

  return count;
}
