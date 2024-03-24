// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if ((arr[i] + arr[j]) == value)
                count++;
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int right = len - 1;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}

int binsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int leftPos = mid - 1;
            while (leftPos >= 0 && arr[leftPos] == value) {
                count++;
                leftPos--;
            }
            int rightPos = mid + 1;
            while (rightPos < size && arr[rightPos] == value) {
                count++;
                rightPos++;
            }
            return count;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int secondElem = value - arr[i];
        count = count + binsearch(&arr[i + 1], len - i - 1, secondElem);
    }
    return count;
}
