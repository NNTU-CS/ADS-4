// Copyright 2021 NNTU-CS
void quickSort(int* arr, int left, int right) {
    if (left < right) {
    int pov = arr[left + (right - left) / 2];
    int l = left, r = right;
    while (l <= r) {
        while (arr[l] < pov) l++;
        while (arr[r] > pov) r--;
        if (l <= r) {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    quickSort(arr, left, r);
    quickSort(arr, l, right);
    }
}

int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            cnt++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int low = i + 1;
        int high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int first = low;
        low = i + 1;
        high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int last = high;
        if (first <= last) {
            cnt += last - first + 1;
        }
    }
    return cnt;
}
