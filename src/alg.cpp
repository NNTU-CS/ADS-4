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
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
                break;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
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
        if (left < len && arr[left] == other) {
            int first = left;
            int last = first;
            right = len - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] <= other) {
                    left = mid + 1;
                    last = mid;
                } else {
                    right = mid - 1;
                }
            }
            count += (last - first + 1);
        }
    }
    return count;
}
