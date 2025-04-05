// Copyright 2021 NNTU-CS

#include <iostream>

int CountPairs1(const int* array, int length, int target_sum) {
  int pair_count = 0;
  for (int i = 0; i < length; ++i) {
    for (int j = i + 1; j < length; ++j) {
      if (array[i] + array[j] == target_sum) {
        ++pair_count;
      }
    }
  }
  return pair_count;
}

int CountPairs2(const int* array, int length, int target_sum) {
  int pair_count = 0;
  int left = 0;
  int right = length - 1;

  while (left < right) {
    const int current_sum = array[left] + array[right];
    if (current_sum < target_sum) {
      ++left;
    } else if (current_sum > target_sum) {
      --right;
    } else {
      if (array[left] == array[right]) {
        const int duplicate_count = right - left + 1;
        pair_count += duplicate_count * (duplicate_count - 1) / 2;
        break;
      }

      int left_duplicates = 1;
      int current_left = left;
      while (current_left + 1 < right && 
             array[current_left + 1] == array[left]) {
        ++left_duplicates;
        ++current_left;
      }

      int right_duplicates = 1;
      int current_right = right;
      while (left < current_right - 1 && 
             array[current_right - 1] == array[right]) {
        ++right_duplicates;
        --current_right;
      }

      pair_count += left_duplicates * right_duplicates;
      left = current_left + 1;
      right = current_right - 1;
    }
  }
  return pair_count;
}

int BinarySearchFirst(const int* array, int high, int low, int target) {
  int result = -1;
  while (low <= high) {
    const int mid = low + (high - low) / 2;
    if (array[mid] == target) {
      result = mid;
      high = mid - 1;
    } else if (array[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}

int BinarySearchLast(const int* array, int high, int low, int target) {
  int result = -1;
  while (low <= high) {
    const int mid = low + (high - low) / 2;
    if (array[mid] == target) {
      result = mid;
      low = mid + 1;
    } else if (array[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}

int CountPairs3(const int* array, int length, int target_sum) {
  int pair_count = 0;
  for (int i = 0; i < length - 1; ++i) {
    const int complement = target_sum - array[i];
    if (complement < array[i]) {
      continue;
    }

    const int low = i + 1;
    const int high = length - 1;
    const int first = BinarySearchFirst(array, high, low, complement);
    if (first == -1) {
      continue;
    }

    const int last = BinarySearchLast(array, high, low, complement);
    pair_count += (last - first + 1);
  }
  return pair_count;
}
