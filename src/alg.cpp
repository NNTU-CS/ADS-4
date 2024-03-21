// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if ((arr[i] + arr[j]) == value)
                res += 1;
    return res;
}
int countPairs2(int* arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > value)
            continue;
        for (int j = len - 1; j > i; j--) {
            if (arr[j] > value)
                continue;
            if ((arr[i] + arr[j]) == value)
                res += 1;
        }
    }
    return res;
}
int countPairs3(int* arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        int left = i;
        int right = size;
        while (left < right - 1) {
            int mid = (right + left) / 2;
            if (arr[i] + arr[mid] == value) {
                count++;
                int j = mid + 1;
                while ((arr[i] + arr[j] == value) && (j < right)) {
                    count++;
                    j++;
                }
            }
            if (arr[i] + arr[mid] < value) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
    }
    return count;
}
