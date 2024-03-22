// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] >= 0 && arr[j] >= 0) && (arr[i] + arr[j] == value)) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int last = len - 1;
    while (arr[last] > value) {
        last--;
    }
    for (int i = 0; i < last; i++) {
        for (int j = last; j > i; j--) {
            if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
                count++;
            } else if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int r, mid, medium, l;
    for (int i = 0; i < len; ++i) {
        r = len - 1;
        l = i + 1;
        medium = value - arr[i];
        while (l <= r) {
            mid = (l + r) / 2;
            if (arr[mid] == medium) {
                count++;
                int next = mid - 1;
                while ((next > i) && (arr[next] == arr[mid])) {
                    count++;
                    next--;
                }
                int p2 = mid + 1;
                while ((i < p2) && (arr[p2] == arr[mid])) {
                    count++;
                    p2++;
                }
                break;
            } else if (arr[mid] > medium) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return count;
}
