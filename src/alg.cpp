// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] > value) continue;
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j + 1]) j++;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) i++;
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_val = arr[left];
            int left_count = 1;
            while (left + 1 < right && arr[left + 1] == left_val) {
                left_count++;
                left++;
            }
            int right_val = arr[right];
            int right_count = 1;
            while (right - 1 > left && arr[right - 1] == right_val) {
                right_count++;
                right--;
            }
            count += left_count * right_count;
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
    for (int i = 0; i < len - 1; ++i) {
        if (arr[i] > value) break;
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                int j = mid - 1;
                while (j >= left && arr[j] == target) {
                    count++;
                    j--;
                }
                j = mid + 1;
                while (j <= right && arr[j] == target) {
                    count++;
                    j++;
                }
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        while (i + 1 < len - 1 && arr[i] == arr[i + 1]) i++;
    }
    return count;
}
