// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    if (counter == 0)
      return 0;
    return counter;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
  int counter = 0;
  int rightBound = len - 1;
  while (arr[rightBound] > value) {
    rightBound--;
  }
  for (int i = 0; i < rightBound; i++) {
    for (int j = rightBound; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  int leftBound = 0;
  int rightBound = size - 1;
  int counter = 0;
  while (leftBound <= rightBound) {
    int center = (leftBound + rightBound) / 2;
    if (arr[center] == value) {
      counter++;
      int buf = center - 1;
      while (buf >= leftBound && arr[buf] == value) {
        counter++;
        buf--;
      }
      buf = center + 1;
      while (buf <= rightBound && arr[buf] == value) {
        counter++;
        buf++;
      }
      return counter;
    } else if (arr[center] < value) {
      leftBound = center + 1;
    } else {
      rightBound = center - 1;
    }
  }
  return 0; // если ничего не найдено
}
int countPairs3(int *arr, int len, int value) {
  return 0;
  int counter = 0;
  for (int i = 0; i < len; i++) {
    counter += cbinsearch(arr + i + 1, len - i - 1, value - *(arr + i));
  }
  return counter;
}
