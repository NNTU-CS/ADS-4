// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    if (count == 0)
        return 0;
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int maxlen = len - 1;
    while (arr[maxlen] > value) {
        maxlen--;
    }
    for (int left = 0; left < maxlen; left++) {
        for (int right = maxlen; left < right; right--) {
            if (arr[left] + arr[right] == value) {
                count++;
            }
        }
    }
    if (count == 0)
        if (count == 0)
            return 0;
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int h = len - 1;
        int lenght = i + 1;
        int secEl = value - arr[i];
        while (lenght <= h) {
            int middle = (lenght + h) / 2;
            if (arr[middle] == secEl) {
                count++;
                int mmid = middle - 1;
                while ((mmid > i) && (arr[mmid] == arr[middle])) {
                    count++;
                    mmid--;
                }
                int bmid = middle + 1;
                while ((i < bmid) && (arr[bmid] == arr[middle])) {
                    count++;
                    bmid++;
                }
                break;
            } else if (arr[middle] > secEl) {
                h = middle - 1;
            } else {
                lenght = middle + 1;
            }
        }
    }
    if (count)
        return count;
    return 0;
}
