// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int *arr, int len, int value) {
    int summ = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (value == arr[i] + arr[j]) {
                summ++;
            }
        }
    }
    return summ;
}
int countPairs2(int *arr, int len, int value) {
    int summ = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len-1; j > i; --j) {
            if (value == arr[i] + arr[j]) {
                summ++;
            }
        }
    }
    return summ;
}
int countPairs3(int* arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len - 1; i++) {
    int l_bound = i;
    int r_bound = len;
    while (l_bound < r_bound - 1) {
        int middle = (r_bound + l_bound) / 2;
        if (arr[i] + arr[middle] == value) {
            result++;
            int j = middle + 1;
            while ((arr[i] + arr[j] == value) && (j < r_bound)) {
                result++;
                j++;
            }
            j = middle - 1;
            while ((arr[i] + arr[j] == value) && (j > l_bound)) {
                result++;
                j--;
            }
            break;
            } else if (arr[i] + arr[middle] > value) {
                r_bound = middle;
            } else {
                l_bound = middle;
            }
        }
    }
    return result;
}
