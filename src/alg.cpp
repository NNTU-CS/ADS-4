// Copyright 2021 NNTU-CS
void quickSort(int* arr, int left, int right) {
    if (left < right) {
        int pov = arr[left + (right - left) / 2];
        int l = left;
        int r = right;
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
    quickSort(arr, 0, len - 1);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
            if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int cnt = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                cnt += n * (n - 1) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_cnt = 0;
            int right_cnt = 0;
            while (left <= right && arr[left] == left_val) {
                left_cnt++;
                left++;
            }
            while (right >= left && arr[right] == right_val) {
                right_cnt++;
                right--;
            }
            cnt += left_cnt * right_cnt;
        }
        else if (sum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int cnt = 0;
    
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                cnt++;
                int j = mid - 1;
                while (j >= left && arr[j] == target) {
                    cnt++;
                    j--;
                }
                j = mid + 1;
                while (j <= right && arr[j] == target) {
                    cnt++;
                    j++;
                }
                break;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return cnt;
}
