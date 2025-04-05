// Copyright 2021 NNTU-CS
void sort(int* array, int left, int right) {
    if (left < right) {
        int pivot = array[left + (right - left) / 2];
        int l = left, r = right;
        while (l <= r) {
            while (array[l] < pivot) l++;
            while (array[r] > pivot) r--;
            if (l <= r) {
                int temp = array[l];
                array[l] = array[r];
                array[r] = temp;
                l++;
                r--;
            }
        }
        sort(array, left, r);
        sort(array, l, right);
    }
}
int countPairs1(int* array, int size, int targetSum) {
    sort(array, 0, size - 1);
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
    sort(array, 0, size - 1);
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
    sort(array, 0, size - 1);
    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        int complement = targetSum - array[i];
        if (bin(array, size, complement, i) != -1) {
            count++;
        }
    }
    return count;
}
