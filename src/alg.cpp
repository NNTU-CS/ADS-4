// Copyright 2021 NNTU-CS

int countPairs1(int* array, int length, int target_sum) {
  int pair_count = 0;
  for (int first = 0; first < length; ++first) {
    for (int second = first + 1; second < length; ++second) {
      if (array[first] + array[second] == target_sum) {
        pair_count++;
      }
    }
  }
  return pair_count;
}

int countPairs2(int* array, int length, int target_sum) {
  int pair_count = 0;
  int left_index = 0;
  int right_index = length - 1;

  while (left_index < right_index) {
    int current_sum = array[left_index] + array[right_index];
    if (current_sum == target_sum) {
      if (array[left_index] == array[right_index]) {
        int duplicates = right_index - left_index + 1;
        pair_count += duplicates * (duplicates - 1) / 2;
        break;
      } else {
        int left_value = array[left_index];
        int right_value = array[right_index];
        int left_duplicates = 0;

        while (left_index < length && array[left_index] == left_value) {
          left_index++;
          left_duplicates++;
        }
        while (right_index >= 0 && array[right_index] == right_value) {
          right_index--;
          right_duplicates++;
        }
        pair_count += left_duplicates * right_duplicates;
      }
    } else if (current_sum < target_sum) {
      left_index++;
    } else {
      right_index--;
    }
  }
  return pair_count;
}

int binarySearchFunction(int* array, int low, int high, int key) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] == key) {
      return mid;
    } else if (array[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int* array, int length, int target_sum) {
  int pair_count = 0;
  for (int i = 0; i < length; ++i) {
    int complement = target_sum - array[i];
    int found_index = binarySearchFunction(array, i + 1, length - 1, complement);
    if (found_index != -1) {
      pair_count++;
      int left = found_index - 1;
      while (left > i && array[left] == complement) {
        pair_count++;
        left--;
      }
      int right = found_index + 1;
      while (right < length && array[right] == complement) {
        pair_count++;
        right++;
      }
    }
  }
  return pair_count;
}
