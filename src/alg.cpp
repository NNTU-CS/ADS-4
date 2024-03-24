// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    int high  = len - 1;
    while (arr[high] > value) {
        high = high - 1;
    }
    for (int i = 0; i < high; i++) {
        for (int j = high; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int lower = 0;
    int high = size - 1;
    while (lower <= high) {
        int mid = (lower + high) / 2;
        if (arr[mid] < value) {
            lower = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int per = mid-1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[per] == value) {
                count++;
                per--;
            }
            break;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    int i = 0;
    while (arr[i] <= (value / 2) - 1) {
        int bin  = value - arr[i];
        counter += cbinsearch(arr, len, bin);
        i++;
    }
    int mid = cbinsearch(arr, len, value/2);
    counter += mid * (mid - 1) / 2;
    return counter;
}
