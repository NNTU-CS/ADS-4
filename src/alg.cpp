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
    if (count == 0) {
        return 0;
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            count++;
            left++;
            right--;
        } else if (arr[left] + arr[right] < value) {
            left++;
        } else {
            right--;
        }
    }
    if (count == 0) {
        return 0;
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int i = mid - 1;
            while (i >= left && arr[i] == value) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i <= right && arr[i] == value) {
                count++;
                i++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (count == 0) {
        return 0;
    }
    return count;
}
