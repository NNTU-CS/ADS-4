// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
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

int countPairs2(int *arr, int len, int value) {
    int j = len - 1;
    int count = 0;
    while (arr[j] > value) {
        j--;
    }
    for (int i = 0; i < j; i++) {
        for (int n = j; n > i; n--) {
            if (arr[i] + arr[n] == value) {
                count++;
            }
        }
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int iLeft = 0;
    int iRight = size - 1;
    int iCounter = 0;
    while (iLeft <= iRight) {
        int iMid = iLeft + (iRight - iLeft) / 2;
        if (arr[iMid] == value) {
            iCounter++;
            iLeft = iMid - 1;
            iRight = iMid + 1;
            while (iLeft >= 0 && arr[iLeft] == value) {
                iCounter++;
                iLeft--;
            }
            while (iRight < size && arr[iRight] == value) {
                iCounter++;
                iRight++;
            }
            break;
        } else if (value > arr[iMid]) {
            iLeft = iMid + 1;
        } else {
            iRight = iMid - 1;
        }
    }
    return iCounter;
}

int countPairs3(int *arr, int len, int value) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return sum;
}
