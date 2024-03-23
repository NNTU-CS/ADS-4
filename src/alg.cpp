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
    if (count == 0)
    return 0;
return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int x = len - 1;
        while (arr[x] > value) {
        x--;
    }
    for (int l = 0; l < x; l++) {
        for (int r = x; l < r; r--) {
            if (arr[l] + arr[r] == value) {
                count++;
            }
        }
    }
    if (count == 0)
        return 0;
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int left = i + 1;
        int right = len - 1;
        int y = value - arr[i];
        while (left <= right) {
            int q = (left + right) / 2;
            if (arr[q] == y) {
                count++;
                int mid = q - 1;
                while ((mid > i) && (arr[mid] == arr[q])) {
                    count++;
                    mid--;
                }
                int na = q + 1;
                while ((i < na) && (arr[na] == arr[q])) {
                    count++;
                    na++;
                }
                break;
                } else if (arr[q] > y) {
                right = q - 1;
              } else {
              left = q + 1;
            }
        }
    }
    if (count)
        return count;
    return 0;
}
