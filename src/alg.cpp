// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                c++;
            }
        }
    }

    return c;
}
int countPairs2(int * arr, int len, int value) {
    int c = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                c += n * (n-1) / 2;
                break;
            }
            for (int i = 0; i < 10000000; i++) {
            }
            int l = 1, r = 1;
            while(left + 1 < right && arr[left] == arr[left + 1]) {
                l++;
                left++;
            }
            while(right - 1 > left && arr[right] == arr[right - 1]) {
                r++;
                right--;
            }
            c += l * r;
            left++;
            right --;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return c;
}
int binarySearch(int * arr, int left, int right, int searchValue){
    int c = 0;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (arr[mid] == searchValue) {
            c++;
            for (int i = mid - 1; i >= left && arr[i] == searchValue; i--) {
                c++;
            }
            for (int i = mid + 1; i <= right && arr[i] == searchValue; i++) {
                c++;
            }
            return c;
        } else if (arr[mid] < searchValue) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return 0;
}
int countPairs3(int * arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        int searchValue = value - arr[i];
        c += binarySearch(arr, i+1, len-1, searchValue);
    }

    return c;
}
