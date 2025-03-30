// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int col = 0;
    for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
    if (arr[i] + arr[j] == value) {
    col++;
    }
    }
    }
    return col;
}
int countPairs2(int *arr, int len, int value) {
    int col = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        for (int j = i + 1; j < len; j++) {
            if (arr[j] == target) {
                col++;
            }
        }
    }
    return col;
}
int countPairs3(int *arr, int len, int value) {
    int col = 0;
    for (int i = 0; i < len - 1; ++i) {
        int other = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= other) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int first = left;
        if (first >= len || arr[first] != other) continue;
        right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= other) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        col += (right - first + 1);
    }
    return col;
}
