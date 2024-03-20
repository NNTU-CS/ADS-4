// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    int k = 0;
    while (k < len) {
    int i = k + 1;
    while (i < len) {
      if ((arr[k] + arr[i]) == value) {
        count++;
      }
      i++;
    }
    k++;
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int k = len - 1;
    do {
    k = k - 1;
    } 
    while (arr[k] > value) {
    int i = 0;
    while (i < endl) {
      int j = endl;
        while (j > i) {
          if (arr[j] + arr[i] == value) {
            count++;
          }
          j--;
        }
        i++;
    }
    }
    return count;
}
int cbinsearch(int *arr, int size, int value) {
    int i = 0;
    int count = 0; 
    int high = size - 1;
    while (i <= high) {
        int mid = (high + i) / 2;
        if (arr[mid] < value) {
            i = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int now = mid - 1;
            mid++;
            while (arr[mid] == value) {
                mid++;
                count++;
            }
            while (arr[now] == value) {
                now--;
                count++;
            }
            break;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int i = 0;
    int count = 0;
    while (arr[i] <= (value / 2) -1) {
        int num = value - arr[i];
        count += cbinsearch(arr, len, num);
        i++;
    }
    int middle = cbinsearch(arr, len, value / 2);
    count += middle * (middle - 1) / 2;
    return count;
}
