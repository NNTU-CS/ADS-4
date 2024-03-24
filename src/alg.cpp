// Copyright 2021 NNTU-CS
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


int countPairs1(int *arr, int len, int value) {
  int sum = 0, j = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        sum++;
      }
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
  std::vector<int> vectorarr(arr, arr + len);
  int amount = 0;
  int vect_size = vectorarr.size();

  for (int i = 0; i < vect_size; i++) {
    int prec = vect_size / 2;
    int point = prec;
    // if ((point <0)||(point>vect_size)){
    //     point = 0;
    // }
    int search = value - vectorarr.at(i);
    int amount_of_cycles = sqrt(vect_size) + 1;

    for (int a = 0; a < (amount_of_cycles); a++) {
      prec /= 2;
      if (prec == 0) {
        prec = 1;
      }
      int now_value = vectorarr.at(point);

      // рассчет схожести и удаление
      if (now_value == search) {
        amount++;
        vectorarr.erase(begin(vectorarr) + point);
        vect_size--;
        // std::cout << point << " " << now_value << std::endl;
      }

      // рассчет точки
      if (now_value > search) {
        point -= prec;
        if (point < 0) {
          point = 0;
        //   break;
        }
      } else if (now_value < search) {
        point += prec;
        if (point > vect_size) {
          point = vect_size;
        //   break;
        }
      }
    }
  }
  return amount;
}
