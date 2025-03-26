// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
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
int binarySearchFirst(int *arr, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
int binarySearchLast(int *arr, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1])
            continue;
        int current = arr[i];
        int target = value - current;
        if (current == target) {
            int left = i, right = len - 1;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (arr[mid] > current) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            int count_current = right - i + 1;
            count += (count_current * (count_current - 1)) / 2;
        } else {
            int first = binarySearchFirst(arr, i + 1, len - 1, target);
            if (first != -1) {
                int last = binarySearchLast(arr, first, len - 1, target);
                int count_current = i;
                while (count_current < len && arr[count_current] == current)
                    count_current++;
                count_current -= i;
                count += count_current * (last - first + 1);
            }
        }
    }
    return count;
}
