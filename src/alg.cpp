// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    int rightBound = len - 1;
    while (arr[rightBound] > value) {
        rightBound--;
    }

    for (int i = 0; i < rightBound; i++) {
        for (int j = rightBound; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                counter++;
            } else if (arr[i] + arr[j] < value) {
                break;
            }
        }
    }
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len - 1; i++) {
        int leftBound = i;
        int rightBound = len;
        while (leftBound < rightBound - 1) {
            int center = (rightBound + leftBound) / 2;
            if (arr[i] + arr[center] == value) {
                counter++;
                int j = center + 1;
                while ((arr[i] + arr[j] == value) && (j < rightBound)) {
                    counter++;
                    j++;
                }
                j = center - 1;
                while ((arr[i] + arr[j] == value) && (j > leftBound)) {
                    counter++;
                    j--;
                }
                break;
            } else if (arr[i] + arr[center] > value) {
                rightBound = center;
            } else {
                leftBound = center;
            }
        }
    }
    return counter;
}
