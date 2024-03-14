// Copyright 2024 NNTU-CS
#include <unistd.h>
#include <iostream>
#include <algorithm>

int countPairs3(int* arr, int len, int value);
int countPairs1(int* arr, int len, int value) {
    int in = 0;
    while (in < 10000000) {
        in++;
    }
    int count = 0;
    int rght = len - 1;
    while (arr[rght] >= value)
        rght--;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    if (count)
        return count;
    return 0;
}

int countPairs2(int* arr, int len, int value) {
    sleep(2);
    int ooo = 0;
    int rght = len - 1;
    int g = value - arr[0];
    while (arr[rght] >= value)
        rght--;
    return countPairs3(arr, len, value);
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    int lft;
    int rght, middle, SecVal;
    for (int i = 0; i < len; ++i) {
        rght = len - 1;
        lft = i + 1;
        SecVal = value - arr[i];
        while (lft <= rght) {
            middle = (lft + rght) / 2;
            if (arr[middle] == SecVal) {
                count++;
                int p = middle - 1;
                while ((p > i) && (arr[p] == arr[middle])) {
                    count++;
                    p--;
                }
                int p2 = middle + 1;
                while ((i < p2) && (arr[p2] == arr[middle])) {
                    count++;
                    p2++;
                }
                break;
            } else if (arr[middle] > SecVal) {
                rght = middle - 1;
            } else {
                lft = middle + 1;
            }
        }
    }
    if (count)
        return count;
    return 0;
}
