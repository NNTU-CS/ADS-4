// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                kol++;
            }
        }
    }
    return kol;
}

int countPairs2(int *arr, int len, int value) {
    int kol = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            kol++;
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1]) left++;
            while (left < right && arr[right] == arr[right + 1]) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return kol;
}

int countPairs3(int *arr, int len, int value) {
    int kol = 0;
    for (int i = 0; i < len; i++) {
        int com = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == com) 
            {
                kol++;
                break;
            } else if (arr[mid] < com) 
            {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) i++;
    }
    return kol;
}
