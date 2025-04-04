// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j+1 < len && arr[j] == arr[j+1]) j++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len-1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                count += (right-left+1)*(right-left)/2;
                break;
            }
            int l = left;
            int r = right;
            while (arr[l] == arr[left]) l++;
            while (arr[r] == arr[right]) r--;
            count += (l-left)*(right-r);
            left = l;
            right = r;
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
        int low = i+1;
        int high = len-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (arr[mid] == target) {
                count++;
                int l = mid-1;
                while (l >= low && arr[l] == target) {
                    count++;
                    l--;
                }
                int r = mid+1;
                while (r <= high && arr[r] == target) {
                    count++;
                    r++;
                }
                break;
            } else if (arr[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return count;
}
