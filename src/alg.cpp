// Copyright 2021 NNTU-CS
// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >=0 && arr[j] >= 0)) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
  int counter = 0;
  int right = len - 1;
  while (arr[right] > value) {
    right--;
  }
  for (int i =0; i < right; i++) {
    for (int j = right; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >=0 && arr[j] >= 0)) {
        counter++;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len;
    while (left < right - 1) {
      int centre = (right + left) / 2;
      if (arr[i] + arr[centre] == value) {
        counter++;
        int temp = centre + 1;
        while ((arr[i] + arr[temp] == value) && (temp < right)) {
          temp++;
          counter++;
        }
        temp = centre - 1;
        while ((arr[i] + arr[temp] == value) && (temp > left)) {
          temp--;
          counter++;
        }
        break;
      } else if (arr[i] + arr[centre] > value) {
        right = centre;
      } else {
        left = centre;
      }
    }
  }
  return counter;
}
