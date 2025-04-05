// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
            {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            int left_value = arr[left];
            int right_value = arr[right];
            while (left < right && arr[left] == left_value)
                left++;
            while (left < right && arr[right] == right_value)
                right--;
        }
        else if (sum < value) left++;
        else right--;
    }
    return count;
}

int binarySearch(int* arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int target = value - arr[i];
        int index = binarySearch(arr, i + 1, len - 1, target);
        if (index != -1) {
            if (index == i + 1 || arr[index - 1] != target)
                count++;
        }
    }
    return count;
}
