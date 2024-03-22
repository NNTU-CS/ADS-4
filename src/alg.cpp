// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int lo = 0;
    int hi = len - 1;
    while (lo < hi) {
        int sum = arr[lo] + arr[hi];
        if (sum == value) {
            count++;
            lo++;
            hi--;
        } else if (sum < value) {
            lo++;
        } else {
            hi--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int sum = arr[i] + arr[mid];
            if (sum == value) {
                count++;
                break;
            } else if (sum < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
