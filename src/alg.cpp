// Copyright 2021 NNTU-CS
void quickSort(int* arr, int left, int right) {
    while (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        if (j - left < right - i) {
            quickSort(arr, left, j);
            left = i;
        } else {
            quickSort(arr, i, right);
            right = j;
        }
    }
}
int countPairs1(int* arr, int len, int value) {
    quickSort(arr, 0, len - 1);
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
int countPairs2(int* arr, int len, int value) {
    quickSort(arr, 0, len - 1);
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
            
            while (left < len && arr[left] == left_val) {
                left_count++;
                left++;
            }
            while (right >= 0 && arr[right] == right_val) {
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
    quickSort(arr, 0, len - 1);
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
