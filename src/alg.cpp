// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count1;
        break;
      }
    }
  }
  return count1;
}

int countPairs2(int *arr, int len, int value) {
  int count2 = 0;
  int leftin = 0;
  int rightin = len - 1;
  while (leftin < rightin) {
    int summ = arr[leftin] + arr[rightin];
    if (summ == value) {
      ++count2;
      ++leftin;
      --rightin;
    } else if (summ < value) {
      ++leftin;
    } else {
      --rightin;
    }
  }
  return count2;
}

int binarySecondSearch(int *arr, int leftin, int rightin, int target) {
  while (leftin <= rightin) {
    int midin = leftin + (rightin - leftin) / 2;
    if (arr[midin] == target) {
      return midin;
    } else if (arr[midin] < target) {
      leftin = midin + 1;
    } else {
      rightin = midin - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count3 = 0;
  for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if (binarySecondSearch(arr, i + 1, len - 1, complement) != -1) {
            ++count3;
        }
    }
    return count3;
}


