// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }

    return count;
}
int countPairs2(int* arr, int len, int value) {
    int k = len - 1;
    int count = 0;
    while (arr[k] > value) {
        k--;
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j=k; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int cbinsearch(int* arr, int size, int value) {
    int l = 0;
    int r = size - 1;
    int count = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == value) {
            count++;
            l = mid - 1;
            r = mid + 1;
            while (l >= 0 && arr[l] == value) {
                count++;
                l--;
            }
            while (r < size && arr[r] == value) {
                count++;
                r++;
            }
            break;
        } else if (value > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return count;
}
