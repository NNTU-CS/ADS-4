// Copyright 2021 NNTU-CS
// Наивный метод с двойным циклом (O(n²))
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

// Метод двух указателей (O(n))
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            // Обработка дубликатов
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            
            int left_count = 1;
            int right_count = 1;
            
            while (left + left_count < right && arr[left] == arr[left + left_count]) {
                left_count++;
            }
            
            while (right - right_count > left && arr[right] == arr[right - right_count]) {
                right_count++;
            }
            
            count += left_count * right_count;
            left += left_count;
            right -= right_count;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

// Бинарный поиск (O(n log n))
int binarySearchFirst(int *arr, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid - 1;
            if (arr[mid] == target) result = mid;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int binarySearchLast(int *arr, int left, int right, int target) {
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
            if (arr[mid] == target) result = mid;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        int first = binarySearchFirst(arr, i + 1, len - 1, complement);
        if (first != -1) {
            int last = binarySearchLast(arr, first, len - 1, complement);
            count += last - first + 1;
        }
    }
    return count;
}
