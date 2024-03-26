// Copyright 2021 NNTU-CS

int binSearch(int* arr, int len, int value) {
    int count = 0;
    int lt = 0;
    int rt = len - 1;
    while (lt <= rt) {
        int midl = lt + (rt - lt) / 2;
        if (arr[midl] == value) {
            count++;
            int lt = midl - 1;
            int rt = midl + 1;
            while (lt >= 0 && arr[lt] == value) {
                count++;
                lt--;
            }
            while (rt < len && arr[rt] == value) {
                count++;
                rt++;
            }
            return count;
        }
        if (arr[midl] < value) {
            lt = midl + 1;
        } else {
            rt = midl - 1;
        }
    }
    return count;
}
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = (i + 1); j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int lt = 0;
    int rt = len - 1;
    while (arr[rt] > value) {
        rt = rt - 1;
    }
    for (int i = 0; i < rt; i++) {
        for (int j = rt; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        count += binSearch(&arr[i + 1], len - i - 1, second);
    }
    return count;
}
