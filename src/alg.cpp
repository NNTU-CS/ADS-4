// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}
int countPairs2(int *arr, int len, int value) {
    int k = 0;
    int high = len - 1;
    while (arr[high] > value) {
        high = high - 1;
    }
    for (int i = 0; i < high; i++) {
        for (int j = high; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}
int cbinsearch(int *arr, int size, int value) {
    int low = 0, k = 0, high = size - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            k++;
            int now = mid - 1;
            mid++;
            while (arr[mid] == value) {
                mid++;
                k++;
            }
            while (arr[now] == value) {
                now--;
                k++;
            }
            break;
        }
    }
    return k;
}
int countPairs3(int *arr, int len, int value) {
    int i = 0, k = 0;
    while (arr[i] <= (value / 2) -1) {
        int num = value - arr[i];
        k += cbinsearch(arr, len, num);
        i++;
    }
    int mid = cbinsearch(arr, len, value / 2);
    k += mid * (mid - 1) / 2;
    return k;
}
