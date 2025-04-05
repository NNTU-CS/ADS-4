// Copyright 2021 NNTU-CS
void Sort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int countPairs1(int* array, int size, int targetSum) {
    Sort(array, size);
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i] + array[j] == targetSum) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* array, int size, int targetSum) {
    Sort(array, size);
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int currentSum = array[left] + array[right];
        if (currentSum == targetSum) {
            count++;
            left++;
            right--;
        } else if (currentSum < targetSum) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int bin(int* array, int size, int target, int startIndex) {
    int left = startIndex + 1;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid; 
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int countPairs3(int* array, int size, int targetSum) {
    Sort(array, size);
    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        int complement = targetSum - array[i];
        if (bin(array, size, complement, i) != -1) {
            count++;
        }
    }

    return count;
}
