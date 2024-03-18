// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int low = 0;
    int high = size - 1;
    int count = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int index = mid - 1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[index] == value) {
                count++;
                index--;
            }
            break;
        }
    } return count;
}

int countPairs1(int *arr, int len, int value) {
  return 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
    int count = 0;
    int j  = len -1;
    while (arr[j] > value) {
        j--;
    }
    len = j + 1;
    count += countPairs1(arr, len, value);
    return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, i = 0, el;
  while (i < len) {
      el = value - arr[i];
      count += binarySearch(arr, el, i + 1, len - 1);
      i++;
  }
  return count;
}
