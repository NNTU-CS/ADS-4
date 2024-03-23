// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int cnt{};
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                cnt++;
        }
    }
    return cnt;
}
int countPairs2(int* arr, int len, int value) {
    int r = len - 1;
    int cnt{};
    while (arr[r] > value) {
        r = r - 1;
    }
    for (int i = 0; i < r; i++) {
        for (int j = r; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}
int countPairs3(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        int l = i, r = len;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            if (arr[i] + arr[mid] == value) {
                k++;
                int j = mid + 1;
                while (arr[i] + arr[j] == value && j < r) {
                    k++;
                    j++;
                }
                j = mid - 1;
                while (arr[i] + arr[j] == value && j > l) {
                    k++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[mid] > value)
                r = mid;
            else
                l = mid;
        }
    }
    return k;
}
