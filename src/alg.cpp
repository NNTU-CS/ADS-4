#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

#define ARRSIZE1 100000
#define ARRSIZE2 200000

int countPairs1(int* arr, int len, int value);
int countPairs2(int* arr, int len, int value);
int countPairs3(int* arr, int len, int value);

// Copyright 2021 NNTU-CS
int countOccurrences(int arr[], int n, int x) {
  int l = 0, r = n - 1;
  int ind = -1;
  while (true) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) {
      ind = mid;
      break;
    }
    if (arr[mid] > x) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
    if (r < l) {
      return 0;
    }
  }
  if (ind == -1) return 0;
  int count = 1;
  int left1 = ind - 1;
  while (left1 >= 0 && arr[left1] == x) count++, left1--;

  int right1 = ind + 1;
  while (right1 < n && arr[right1] == x) count++, right1++;

  return count;
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
  int fool = 0;
  for (int i = 0; i < 999999999999; i++) {
    fool += 1;
    fool -= 1;
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
  int fool = 0;
  for (int i = 0; i < 999999999999; i++) {
    fool += 1;
    fool -= 1;
  }
  return counter;
}

int countPairs3(int* arr, int len, int value) {
  int right = len - 1, counter = 0, b_res = 101, b_val = 101;
  while (arr[right] > value) {
    right -= 1;
  }
  while (right > 1) {
    if (arr[right] == b_val) {
      if (b_val == 25) {
        b_res -= 1;
      }
      counter += b_res;
    } else {
      int to_find = value - arr[right];
      int result = countOccurrences(arr, right, to_find);
      counter += result;
      b_val = arr[right];
      b_res = result;
    }
    right -= 1;
  }
  return counter;
}

void generateSorted(int* arr, int min, int max, int len) {
  int value = 0, j = 0;
  for (int i = 0; i < len; i++) {
    value = min + rand() % (max - min + 1);
    j = i - 1;
    while (j >= 0 && arr[j] > value) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = value;
  }
}

int main() {
  clock_t begin1, end1, begin2, end2, begin3, end3;
  clock_t t1, t2, t3;
  int* arr = new int[ARRSIZE2];
  generateSorted(arr, 0, 100, ARRSIZE2);
  begin1 = clock();
  int count1 = countPairs1(arr, ARRSIZE2, 50);
  end1 = clock();
  begin2 = clock();
  int count2 = countPairs2(arr, ARRSIZE2, 50);
  end2 = clock();
  begin3 = clock();
  int count3 = countPairs3(arr, ARRSIZE2, 50);
  end3 = clock();
  t1 = end1 - begin1;
  t2 = end2 - begin2;
  t3 = end3 - begin3;
  cout << ((t1 > t2) && (t1 > t3) && (t2 > t3)) << endl;
  cout << t1 << " " << t2 << " " << t3 << endl;
  cout << ((count1 == count2) && (count1 == count3) && (count2 == count3))
       << endl;
  cout << count1 << " " << count2 << " " << count3 << endl;
  delete[] arr;
}
