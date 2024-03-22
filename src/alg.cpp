// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
  int left = 0, right = size - 1;
  int middle = (right + left) / 2, counter = 0;
  while (arr[middle] != value) {
    if (arr[right] == value) {
      middle = right;
      break;
    } else if (arr[left] == value) {
      middle = left;
      break;
    }
    if (right == middle || left == middle) {
      return 0;
    }
    if (arr[middle] < value) {
      left = middle;
    } else if (arr[middle] > value) {
      right = middle;
    }
    middle = (right + left) / 2;
  }
  counter += 1;
  bool one = true, two = true;
  int index1 = middle - 1, index2 = middle + 1;
  while (true) {
    if (one) {
      if (index1 < 0 || index1 > size - 1) {
        one = false;
      } else {
        if (arr[index1] == value) {
          counter += 1;
        }
      }
    }
    if (two) {
      if (index2 < 0 || index2 > size - 1) {
        two = false;
      } else {
        if (arr[index2] == value) {
          counter += 1;
        }
      }
    }
    index1 -= 1;
    index2 += 1;
    if (!one && !two) {
      break;
    }
  }
  return counter;  // если ничего не найдено
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
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  int right = len - 1, counter = 0, boofer = -1, pre_elem = -1;
  while (arr[right] > value) {
    --right;
  }
  while (right) {
    if (pre_elem == arr[right]) {
      counter += boofer;
    } else {
      int to_find = value - arr[right];
      int result = cbinsearch(arr, right, to_find);
      counter += result;
      boofer = result;
      pre_elem = arr[right];
    }
    right -= 1;
  }
  return counter;
}
