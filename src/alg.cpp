// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int j = 0; j < len - 1; j++) {
        for (int i = j + 1; i < len; i++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int j = len - 1;
    int k = 0;
    while (arr[j] > value) {
        j--;
    }
    for (int i = 0; i < j; i++) {
        for (int n = j; n > i; n--) {
            if (arr[i] + arr[n] == value) {
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
    for (int i = 0; i < len; i++) {
        k += bin(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return k;
}
