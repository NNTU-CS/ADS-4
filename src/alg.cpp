// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j+1]) j++;
            }
        }
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
            if (arr[left] != arr[right]) {
                int left_val = arr[left];
                int right_val = arr[right];
                while (left < len && arr[left] == left_val) left++;
                while (right >= 0 && arr[right] == right_val) right--;
                count++;
            } else {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
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
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        bool found = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                found = true;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (found) {
            int first = left;
            left = i + 1;
            right = len - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            count += right - first + 1;
        }
    }
    return count;
}
