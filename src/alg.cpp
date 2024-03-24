// Copyright 2021 NNTU-CS
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
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int low = 0;
    int count = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int iPer = mid - 1;
            mid++;
            while (arr[mid] == value) {
                mid++;
                count++;
            }
            while (arr[iPer] == value) {
                iPer--;
                count++;
            }
            break;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    while (arr[i] <= (value / 2) -1) {
        int bPer = value - arr[i];
        count += cbinsearch(arr, len, bPer);
        i++;
    }
    int mid = cbinsearch(arr, len, value / 2);
    count += mid * (mid - 1) /  2;
    return count;
}
