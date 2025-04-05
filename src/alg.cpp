// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0;
    int end = len - 1;
    while (end > 0) {
        if (arr[end] > value) {
            end--;
        } else {
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = end; j > i; j--) {
            if (arr[i] + arr[j] == value)
                cnt++;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int low = i + 1;
        int high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int first = low;
        low = i + 1;
        high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int last = high;
        if (first <= last) {
            cnt += last - first + 1;
        }
    }
    return cnt;
}
