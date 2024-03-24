// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0, x = 0, j = 0;
    for (int i = 0; i < (len - 1); i++) {
        if ((arr[i] + arr[i + 1]) >= value) {
            x = i;
            break;
        }
    }
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        if (x <= i) {
            j = i + 1;
        } else {
            j = x;
        }
        for (; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
            if (arr[j] > value) {
                break;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0, y = 0, left = 0, right = len;
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        left = i;
        right = len - 1;
        while (left < right) {
            y = left + ((right - left) / 2);
            if (left == right) {
                break;
            }
            if ((arr[i] + arr[y]) > value) {
                for (int n = (y - 1); n >= left; n--) {
                    right = n + 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                if (right - left == 1) {
                    break;
                }
            }
            if ((arr[i] + arr[y]) < value) {
                for (int n = (y + 1); n <= right; n++) {
                    left = n - 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                if (right - left == 1) {
                    break;
                }
            }
            if ((arr[i] + arr[y]) == value) {
                int t = right;
                for (int n = (y + 1); n <= t; n++) {
                    right = n - 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                t = left;
                for (int n = (y - 1); n >= t; n--) {
                    left = n + 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                break;
            }
        }
        for (int j = left; j <= right; j++) {
            if (((arr[i] + arr[j]) == value) && (i != j)) {
                count++;
            }
        }
    }
    return count;
}
