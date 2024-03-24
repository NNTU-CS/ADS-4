// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int k = 0; k < (len - 1); k++) {
        for (int r = k + 1; r < len; r++) {
            if ((arr[k] + arr[r]) == value) {
                count++;
            }
        }
    }
    if (count > 0) {
        return count;
    }
    return 0;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0, x = 0, r = 0;
    for (int k = 0; k < (len - 1); k++) {
        if ((arr[k] + arr[k + 1]) >= value) {
            x = k;
            break;
        }
    }
    for (int k = 0; k < (len - 1); k++) {
        if (arr[k] > value) {
            break;
        }
        if (x <= k) {
            r = k + 1;
        } else {
            r = x;
        }
        for (; r < len; r++) {
            if ((arr[k] + arr[r]) == value) {
                count++;
            }
            if (arr[r] > value) {
                break;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0, x = 0, min = 0, max = len;
    for (int k = 0; k < (len - 1); k++) {
        if (arr[k] > value) {
            break;
        }
        min = k;
        max = len - 1;
        while (min < max) {
            x = min + ((max - min) / 2);
            if (min == max) {
                break;
            }
            if ((arr[k] + arr[x]) > value) {
                for (int n = (x - 1); n >= min; n--) {
                    max = n + 1;
                    if (arr[x] != arr[n]) {
                        break;
                    }
                }
                if (max - min == 1) {
                    break;
                }
            }
            if ((arr[k] + arr[x]) < value) {
                for (int n = (x + 1); n <= max; n++) {
                    min = n - 1;
                    if (arr[x] != arr[n]) {
                        break;
                    }
                }
                if (max - min == 1) {
                    break;
                }
            }
            if ((arr[k] + arr[x]) == value) {
                int s = max;
                for (int n = (y + 1); n <= s; n++) {
                    max = n - 1;
                    if (arr[x] != arr[n]) {
                        break;
                    }
                }
                s = min;
                for (int n = (y - 1); n >= s; n--) {
                    min = n + 1;
                    if (arr[x] != arr[n]) {
                        break;
                    }
                }
                break;
            }
        }
        for (int r = min; r <= max; r++) {
            if (((arr[k] + arr[r]) == value) && (k != r)) {
                count++;
            }
        }
    }
    return count;
}
