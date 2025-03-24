// Copyright 2021 NNTU-CS
#include <iostream>
#include <unordered_map>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
          if (arr[i] + arr[j] == value) {
              count++;
          }
      }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
      int sum = arr[left] + arr[right];
      if (sum == value) {
          int leftCount = 1;
          int rightCount = 1;
          while (left + 1 < right && arr[left] == arr[left + 1]) {
              leftCount++;
              left++;
          }
          while (right - 1 > left && arr[right] == arr[right - 1]) {
              rightCount++;
              right--;
          }
          count += leftCount * rightCount;
          left++;
          right--;
      } else if (sum < value) {
          left++;
      } else {
          right--;
      }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  std::unordered_map<int, int> frequency;
  for (int i = 0; i < len; i++) {
      frequency[arr[i]]++;
  }
  for (const auto& pair : frequency) {
      int i = pair.first;
      int j = value - i;
      if (frequency.find(j) != frequency.end()) {
          if (i == j) {
              count += (frequency[i] * (frequency[i] - 1)) / 2;
          } else if (frequency.find(j) != frequency.end()) {
              count += pair.second * frequency[j];
          }
      }
  }
  return count/2;
}
