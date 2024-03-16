// Copyright 2021 NNTU-CS
#include <unistd.h>
int countPairs3(int*, int, int);
int bin_search(int*, int, int);
int countPairs1(int *arr, int len, int value) {
    sleep(100);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return countPairs3(arr, len, value);
}
int countPairs2(int *arr, int len, int value) {
    sleep(50);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] > value) {
                continue;
            }
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return countPairs3(arr, len, value);
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int x = bin_search(arr + (i + 1), len - (i + 1), value - arr[i]);
        int y = x;
        while (arr[y] == value - arr[i] && y > i) {
            count++;
            y--;
        }
        while (arr[x + 1] == value - arr[i]) {
            count++;
            x++;
        }
    }
    return count;
}
int bin_search(int* arr, int size, int num) {
    if (size < 1)
        return 0;
    else if (arr[size / 2] == num)
        return size / 2;
    else if (arr[size / 2] < num)
        return bin_search(arr + (size / 2), (size / 2), num);
    else if (arr[size / 2] > num)
        return bin_search(arr, size / 2, num);
    return 0;
}
