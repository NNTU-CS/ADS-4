// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (arr[i] + arr[j] == value)
                k += 1;
        }
    }
    return k;
}

int countPairs2(int* arr, int len, int value) {
    int k = 0;
    int left = 0;
    int reg = len - 1;
    for (int i = 0; i < reg; ++i) {
        for (int j = len - 1; j > left; --j) {
            if (arr[i] + arr[j] == value)
                k += 1;
            if (arr[j] > value)
                reg--;
        }
        left++;
    }
    return k;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int first_pos = len;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= complement) {
                first_pos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        left = i + 1;
        right = len - 1;
        int last_pos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= complement) {
                last_pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (first_pos <= last_pos) {
            count += last_pos - first_pos + 1;
        }
    }
    return count;
}
