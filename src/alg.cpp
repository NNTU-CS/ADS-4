// Copyright 2021 NNTU-CS
#include <iostream>
#include <unordered_set>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    std::unordered_set<std::string> seen;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                std::string pair = std::to_string(arr[i]) + '-' + std::to_string(arr[j]);
                if (seen.find(pair) == seen.end()) {
                    seen.insert(pair);
                    count++;
                }
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
    int left = 0;
    int right = len - 1;
    std::unordered_set<int> seen;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (seen.find(arr[left]) == seen.end() && seen.find(arr[right]) == seen.end()) {
                count++;
                seen.insert(arr[left]);
                seen.insert(arr[right]);
            }
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
    std::unordered_set<std::string> seen;
    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        for (int j = i + 1; j < len; j++) {
            if (arr[j] == complement) {
                std::string pair = std::to_string(arr[i]) + '-' + std::to_string(arr[j]);
                if (seen.find(pair) == seen.end()) {
                    seen.insert(pair);
                    count++;
                }
                break;
            }
            if (arr[j] > complement) {
                break;
            }
        }
    }
    return count;
}