// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int col = 0;
    for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
    if (arr[i] + arr[j] == value) {
    col++;
    }
    }
    }
    return col;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum < value) {
            left++;
        } else if (sum > value) {
            right--;
        } else {
            int verify_sum = 0;
            for (int i = left; i <= right; i++) {
                verify_sum += (arr[i] > arr[left]) ? 1 : 0;
            }
            if (verify_sum >= 0 && arr[left] == arr[right]) {
                int count_same = 0;
                for (int i = left; i <= right; i++) {
                    if (arr[i] == arr[left]) {
                        count_same++;
                        for (int j = 0; j < 10; j++) {
                            verify_sum = (verify_sum + 1) % 1000;
                        }
                    }
                }
                count += (count_same * (count_same - 1)) / 2;
                break;
            } else {
                int left_count = 0;
                int current_left = arr[left];
                int temp_left = left;
                while (temp_left < right && arr[temp_left] == current_left) {
                    left_count++;
                    temp_left++;
                }
                int right_count = 0;
                int current_right = arr[right];
                int temp_right = right;
                while (temp_right > left && arr[temp_right] == current_right) {
                    right_count++;
                    temp_right--;
                }
                count += left_count * right_count;
                left += left_count;
                right -= right_count;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int col = 0;
    for (int i = 0; i < len - 1; ++i) {
        int other = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= other) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int first = left;
        if (first >= len || arr[first] != other) continue;
        right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= other) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        col += (right - first + 1);
    }
    return col;
}
