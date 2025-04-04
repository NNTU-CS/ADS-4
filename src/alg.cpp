// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > value/2) break;
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j + 1]) j++;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) i++;
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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int tmp_left = left;
            int tmp_right = right;
            while (arr[tmp_left] == arr[left]) tmp_left++;
            while (arr[tmp_right] == arr[right]) tmp_right--;
            count += (tmp_left - left) * (right - tmp_right);
            left = tmp_left;
            right = tmp_right;
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
        if (arr[i] > value/2) break;
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (arr[mid] == target) {
                count++;
                int l = mid - 1;
                while (l >= left && arr[l] == target) {
                    count++;
                    l--;
                }
                int r = mid + 1;
                while (r <= right && arr[r] == target) {
                    count++;
                    r++;
                }
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) i++;
    }
    return count;
}
