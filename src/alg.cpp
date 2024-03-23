// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j ++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
int count = 0;
int left = 0; 
int right = len - 1;
while (arr[right] > value)
  right--;
for (int i = 0; i < right; i++) { 
  for (int j = right; i < j; j++) {
    if(arr[i] + arr[j] == value) 
      count++;
  }
}
return count;
}

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == value) {
            count++;
            int neighL = middle - 1;
            while (neighL >= 0 && arr[neighL] == value) {
                count++;
                neighL--;
            }
            int iright = middle + 1;
            while (iright < size && arr[iright] == value) {
                count++;
                iright++;
            }
            return count;
        } else if (arr[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int key = value - arr[i];
    count += cbinsearch(&arr[i+1], len - i - 1, key);
  }
  return count;
}
