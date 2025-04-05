// Copyright 2021 NNTU-CS
int binarySearch(int *arr, int len, int target) {
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
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
            while (left + 1 < right && arr[left] == arr[left + 1]) {
                leftCount++;
                left++;
            }
            int rightCount = 1;
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
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int idx = binarySearch(arr + i + 1, len - i - 1, target);
        if (idx != -1) {
            int leftCount = 1;
            while (i > 0 && arr[i] == arr[i - 1]) {
                leftCount++;
                i--;
            }
            i++;
            int rightCount = 1;
            while (idx + i + 1 < len && arr[idx + i + 1] == arr[idx + i + 2]) {
                rightCount++;
                idx++;
            }
            count += leftCount * rightCount;
        }
    }
    return count;
}
