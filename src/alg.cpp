// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for(int i = 0; i < len-1; ++i) {
        for(int j = i+1; j < len; ++j) {
            if(arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while(left < right) {
        int current_sum = arr[left] + arr[right];
        if(current_sum == value) {
            if(arr[left] == arr[right]) {
                int n = right - left + 1;
                count += (n * (n - 1)) / 2;
                break;
            } else {
                int count_left = 1;
                while(left + 1 < right && arr[left] == arr[left + 1]) {
                    count_left++;
                    left++;
                }
                int count_right = 1;
                while(right - 1 > left && arr[right] == arr[right - 1]) {
                    count_right++;
                    right--;
                }
                count += count_left * count_right;
            }
        }
        if(current_sum < value) {
            left++;
        }
        else if(current_sum > value) {
            right--;
        }
        else {
            left++;
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for(int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if(complement < arr[i]) {
            break;
        }
        int left = i + 1;
        int right = len - 1;
        int first = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == complement) {
                first = mid;
                right = mid - 1;
            }
            else if(arr[mid] < complement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if(first == -1) continue;
        left = first;
        right = len - 1;
        int last = first;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == complement) {
                last = mid;
                left = mid + 1;
            }
            else if(arr[mid] < complement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        count += (last - first + 1);
    }
    return count;
}