// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int high = len - 1;
    while (arr[high] > value) {
        high -= 1;
    }
    for (int i = 0; i < high; i++) {
        for (int j = high; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (arr[middle] == value) {
            count++;
            int iLow = middle - 1;
            while (iLow >= 0 && arr[iLow] == value) {
                count++;
                iLow--;
            }
            int iHigh = middle + 1;
            while (iHigh < size && arr[iHigh] == value) {
                count++;
                iHigh++;
            }
            return count;
        } else if (arr[middle] < value) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return count;
}
