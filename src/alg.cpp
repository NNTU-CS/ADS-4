// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int j = 0; j < len; j++) {
        for (int i = j + 1; i < len; i++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}

int countPairs2(int *arr, int len, int value) {
    int k = 0;
    int max = len - 1;
    while (value < arr[max]) {
        max -= 1;
    }
    for (int i = 0; i < max; i++) {
        for (int j = max; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}

int bin(int *arr, int len, int value) {
    int k = 0;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == value) {
            k++;
            int pup = mid - 1;
            while (pup >= 0 && arr[pup] == value) {
                k++;
                pup--;
            }
            pup = mid + 1;
            while (pup < len && arr[pup] == value) {
                k++;
                pup++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return k;
}

int countPairs3(int *arr, int len, int value) {
    int k = 0;
    for (int j = 0; j < len; j++) {
        k += bin(&arr[j + 1], len - 1, value - arr[j]);
    }
    return k;
}

