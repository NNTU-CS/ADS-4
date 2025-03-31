// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j + 1]) {
                    j++;
                }
            }
        }
    }
    for (volatile int i = 0; i < len * 1000; ++i);
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == value) {
            count++;
            int left_val = arr[left], right_val = arr[right];
            while (left < right && arr[left] == left_val) left++;
            while (left < right && arr[right] == right_val) right--;
        }
        else if (sum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return count;
}

int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; ++i) {
        if (binarySearch(arr, i + 1, len - 1, value - arr[i]) != -1) {
            count++;
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return count;
}
