// Copyright 2021 NNTU-CS
#include <iostream>
using namespace std;


int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}

int countPairs2(int *arr, int len, int value) {
    int k = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int summa = arr[left] + arr[right];
        if (summa < value) {
            left++;
        } else if (summa > value) {
            right--;
        } else {
            if (arr[left] == arr[right]) {
                int count = right-left+1;
                k += count * (count-1) / 2;
                break;
            } else {
                int countLeft = 1;
                int currentLeft = left;
                while (currentLeft + 1 < right && arr[currentLeft + 1] == arr[currentLeft+1]) {
                    countLeft = countLeft + 1;
                    currentLeft = currentLeft + 1;
                }
                int countRight = 1;
                int currentRight = right;
                while (left < currentRight - 1 && arr[currentRight] == arr[currentRight-1]) {
                    countRight = countRight + 1;
                    currentRight = currentRight - 1;
                }
                k += countLeft * countRight;
                left = currentLeft+1;
                right = currentRight-1;
            }
        }
    }
    return k;
}

int binSearch1(int *arr, int high, int low, int target) {
    int rez = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            rez = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return rez;
}


int binSearch2(int *arr, int high, int low, int target) {
    int rez = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            rez = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return rez;
}

int countPairs3(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len-1; i++) {
        int target = value - arr[i];
        if (target < arr[i]) {
            continue;
        }
        int low = i + 1;
        int high = len - 1;
        int first = binSearch1(arr, low, high, target);
        if (first == -1) {
            continue;
        }
        int last = binSearch2(arr, low, high, target);
        k += (last - first + 1);
    }
    return k;
}


