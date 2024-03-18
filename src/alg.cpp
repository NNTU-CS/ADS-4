// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cout = 0;
    while (cout < 1000000) {
        cout++;
    }
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; ++j) {
            if ((arr[i] + arr[j]) == value)
                count++;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int right = len - 1;
    while (arr[right] > value) {
        right--;
    }
    int count = 0;
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int left;
    int right, sered, SrZn;
    for (int i = 0; i < len; ++i) {
        right = len - 1;
        left = i + 1;
        SrZn = value - arr[i];
        while (left <= right) {
            sered = (left + right) / 2;
            if (arr[sered] == SrZn) {
                count++;
                int p = sered - 1;
                while ((p > i) && (arr[p] == arr[sered])) {
                    count++;
                    p--;
                }
                int p2 = sered + 1;
                while ((i < p2) && (arr[p2] == arr[sered])) {
                    count++;
                    p2++;
                }
                break;
            } else if (arr[sered] > SrZn) {
                right = sered - 1;
            } else {
            left = sered + 1;
            }
        }
    }
    return count;
}
