// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
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
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == value) {
            if (arr[left] == arr[right]) {
                count += (right - left) * (right - left + 1) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 1;
            int right_count = 1;
            while (left + 1 < right && arr[left + 1] == left_val) {
                left++;
                left_count++;
            }
            while (right - 1 > left && arr[right - 1] == right_val) {
                right--;
                right_count++;
            }
            count += left_count * right_count;
            left++;
            right--;
        } 
        else if (sum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int target = value - arr[i];
        int low = i + 1;
        int high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                int left = mid;
                int right = mid;
                while (left > low && arr[left - 1] == target) left--;
                while (right < high && arr[right + 1] == target) right++;
                count += right - left + 1;
                break;
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return count;
}
