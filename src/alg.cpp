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
                int left_count = 0;
                int right_count = 0;
                while (left < len && arr[left] == left_val) {
                    left++;
                    left_count++;
                }
                while (right >= 0 && arr[right] == right_val) {
                    right--;
                    right_count++;
                }
                count += left_count * right_count;
            } else {
                count += (right - left + 1) * (right - left) / 2;
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
        int j = i + 1;
        while (j < len && arr[j] <= target) {
            if (arr[j] == target) {
                count++;
                while (j + 1 < len && arr[j] == arr[j+1]) j++;
            }
            j++;
        }
    }
    return count;
}
