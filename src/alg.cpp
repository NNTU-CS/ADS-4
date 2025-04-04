// Copyright 2021 NNTU-CS
void insertionSort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    insertionSort(arr, len);
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                count += (right - left + 1) * (right - left) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 0;
            int right_count = 0;

            while (arr[left] == left_val) {
                left_count++;
                left++;
            }
            while (arr[right] == right_val) {
                right_count++;
                right--;
            }
            count += left_count * right_count;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    insertionSort(arr, len);
    int count = 0;

    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int low = i + 1;
        int high = len - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                count++;
                int left = mid - 1;
                while (left >= low && arr[left] == target) {
                    count++;
                    left--;
                }
                int right = mid + 1;
                while (right <= high && arr[right] == target) {
                    count++;
                    right++;
                }
                break;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return count;
}
