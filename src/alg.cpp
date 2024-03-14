// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) res++;
        }
    }
    if (res == 0) return 0;
    return res;
}
int countPairs2(int *arr, int len, int value) {
    int res = 0;
    int r = len - 1;
    while (arr[r] > value) {
        r--;
    }
    for (int i = 0; i < r; i++) {
        for (int j = r; i < j; j--) {
            if (arr[i] + arr[j] == value) res++;
        }
    }
    if (res == 0) return 0;
    return res;
}
int countPairs3(int *arr, int len, int value) {
    int l = 0;
    int r = 0;
    int m = 0, otv = 0, res = 0, val = 0;
    for (int i = 0; i < len-1; i++) {
        bool flag = false;
        l = i + 1;
        r = len - 1;
        val = value - arr[i];
        while ((l <= r) && (flag != true)) {
            m = (l + r) / 2;
            if (arr[m] == val) {
                flag = true;
                otv = m;
                res++;
            }
            if (arr[m] > val) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        while (arr[m] == val) {
            m++;
            if (arr[m] == val) res++;
        }
        m = otv;
        while ((arr[m] == val) && (--m > i)) {
            if (arr[m] == val) res++;
        }
    }
    if (res == 0) return 0;
    return res;
}
