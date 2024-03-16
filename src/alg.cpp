// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                c++;
            }
        }
    }
    if (c == 0)
        return 0;
    return c;
}
int countPairs2(int* arr, int len, int value) {
    int c = 0;
    int mlen = len - 1;
    while (arr[mlen] > value) {
        mlen--;
    }
    for (int left = 0; left < mlen; left++) {
        for (int right = mlen; left < right; right--) {
            if (arr[left] + arr[right] == value) {
                c++;
            }
        }
    }
    if (c == 0)
        return 0;
    return c;
}
int countPairs3(int* arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; ++i) {
        int h = len - 1;
        int l = i + 1;
        int secEl = value - arr[i];
        while (l <= h) {
            int middle = (l + h) / 2;
            if (arr[middle] == secEl) {
                c++;
                int mmid = middle - 1;
                while ((mmid > i) && (arr[mmid] == arr[middle])) {
                    c++;
                    mmid--;
                }
                int bmid = middle + 1;
                while ((i < bmid) && (arr[bmid] == arr[middle])) {
                    c++;
                    bmid++;
                }
                break;
            } else if (arr[middle] > secEl) {
                h = middle - 1;
            } else {
                l = middle + 1;
            }
        }
    }
    if (c)
        return c;
    return 0;
}
