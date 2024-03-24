// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int size = len - 1;
    while (value < arr[size]) {
        size -= 1;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j > i; j++) {
            if (arr[j] + arr[i] == value) {
                count+=1;
            }
        }
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int midd = left + (right - left) / 2;
        if (arr[midd] < value) {
            left = midd + 1;
        } else if (arr[midd] > value) {
            right = midd - 1;
        } else if (arr[midd] == value) {
            count++;
            right = midd + 1;
            while (arr[right] == value) {
                count++;
                right++;
            }
            left = midd - 1;
            while (arr[left] == value) {
                count++;
                left--;
            }
            break;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count = count + cbinsearch(&arr[i+1], len-1-i, value-arr[i]);
    }
    return count;
}
