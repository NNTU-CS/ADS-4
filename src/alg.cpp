// Copyright 2021 NNTU-CS
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>


int countPairs1(int *arr, int len, int value) {
  int sum = 0, j = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        sum++;
      };
    }
  }
  return sum;
}

int countPairs2(int *arr, int len, int value) {
  int sum = 0;
  for (int j = len - 1; j > 0; --j) {
    if (arr[j] > value) {
      continue;
    }
    for (int i = 0; i < j; ++i) {

      if (arr[j] + arr[i] == value) {
        sum++;
      }
    }
  }
  return sum;
}

int countPairs3(int *arr, int len, int value) {
  int amount = 0;
  for (int i = 0; i < len; i++) {
    int prec = len / 2;
    int point = prec;
    std::vector<int> vectorarr(arr, arr + len);
    int search = value - arr[i];

    for (int a = 0; a < (sqrt(len) + 1); a++) {
      prec /= 2;
      if (prec == 0) {
        prec = 1;
      }
      int now_value = vectorarr.at(point);
      if (now_value == search) {
        amount++;
        vectorarr.erase(begin(vectorarr) + point);
        // std::cout << point << " " << now_value << std::endl;
      } else if (now_value > search) {
        point -= prec;
      } else if (now_value < search) {
        point += prec;
      }
    }
  }
  return amount / 2;
}
