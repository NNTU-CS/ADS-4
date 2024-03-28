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
    int endIndex = len - 1;
    while (endIndex >= 0 && arr[endIndex] > value) {
        endIndex--;
    }
    for (int i = 0; i < endIndex; i++) {
        for (int j = endIndex; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int cbinsearch(int *arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int i = mid - 1;
            while (i >= 0 && arr[i] == value) {
                count++;
                i--;
            }
            int j = mid + 1;
            while (j < size && arr[j] == value) {
                count++;
                j++;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return count;
}
