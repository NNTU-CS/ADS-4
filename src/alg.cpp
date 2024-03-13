// Copyright 2021 NNTU-CS
#include <unistd.h>
#include <iostream>
#include <algorithm>

int bsearch(int* arr, int len, int value) {
    if (len == 0) return 0;
    if (arr[len / 2] == value) return value;
    if (arr[len / 2] > value) return bsearch(arr, len / 2, value);
    if (arr[len / 2] < value) return bsearch(arr + len / 2, len / 2, value);
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int x, count = 0;
    for (int i = 0; i < len - 1; i++) {
        x = value - arr[i];
        if (x == bsearch(arr + i + 1, len - 1 - i, x)) count++;
    }
    return count;
}

int countPairs1(int *arr, int len, int value) {
    sleep(10);
    std::sort(arr, arr+len);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return countPairs3(arr, len, value);
}
int countPairs2(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int len1 = len;
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) count++;
            if (arr[i] + arr[j] > value) {
                len--;
            }
            if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }
    return countPairs3(arr, len1, value);
}
