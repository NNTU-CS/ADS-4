// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int size, int value) {
  int iResult = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if ((arr[i] + arr[j]) == value) {
             iResult += 1;
       }
      }
    }
       return iResult;
}

int countPairs2(int* arr, int len, int value) {
    int left = 0;
    int iResult = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right -= 1;
    }
for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
              iResult++;
            }
        }
    }
    return iResult;
}

int mysearch(int* arr, int size, int value) {
    int right = size - 1;
    int iResult = 0;
    int left = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
             iResult++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
             iResult++;
                left--;
            }
            while (right < size && arr[right] == value) {
                iResult++;
                right++;
            }
            return iResult;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return iResult;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        count += mysearch(&arr[i + 1], len - i - 1, second);
    }
    return count;
}
