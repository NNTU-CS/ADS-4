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
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            cnt++;
            int l = arr[left];
            int r = arr[right];
            while (left < right && arr[left] == l) left++;
            while (left < right && arr[right] == r) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int cnt = 0;
    int l = 0, r = len - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            cnt++;
            l++;
            r--;
            while (l < r && arr[l] == arr[l - 1]) l++;
            while (l < r && arr[r] == arr[r + 1]) r--;
        } else if (sum < value) {
            l++;
        } else {
            r--;
        }
    }
    return cnt;
}
