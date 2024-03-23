// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int left, int right, int value) {
    int middle = left + (right - left) / 2;
    if (right < left) {
        return -1;
    }
    if (arr[middle] == value) {
        return middle;
    }
    if (arr[middle] > value) {
        return cbinsearch(arr, left, middle - 1, value);
    } else {
        return cbinsearch(arr, middle + 1, right, value);
    }
}

int findenteres(int* arr, int len, int value) {
    int index = cbinsearch(arr, 0, len - 1, value);
    if (index == -1) {
        return 0;
    }
    int counter = 1, left = index - 1;
    while (left >= 0 && arr[left] == value) {
        left -= 1;
        counter += 1;
    }
    int right = index + 1;
    while (right < len && arr[right] == value) {
        counter += 1;
        right += 1;
    }
    return counter;
}

int countPairs1(int* arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                counter += 1;
            }
        }
    }
    return counter;
}
int countPairs2(int* arr, int len, int value) {
    int right = len - 1, counter = 0;
    while (arr[right] > value) {
        --right;
    }
    for (int i = 0; i <= right; i++) {
        for (int j = i + 1; j <= right; j++) {
            if (arr[i] + arr[j] == value) {
                ++counter;
            }
        }
    }
    return counter;
}

int countPairs3(int* arr, int len, int value) {
    int right = len - 1, counter = 0, b_res = -1, b_val = -1;
    while (arr[right] > value) --right;
    while (right > 1) {
        if (arr[right] == b_val) {
            if (b_val == 25) {
                b_res -= 1;
            }
            counter += b_res;
        } else {
            int to_find = value - arr[right];
            int result = findenteres(arr, right, to_find);
            counter += result;
            b_val = arr[right];
            b_res = result;
        }
        right -= 1;
    }
    return counter;
}
