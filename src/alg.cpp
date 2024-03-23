// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] >=0 && arr[j] >= 0 && arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    int rightborder = len - 1;
    while (arr[rightborder] > value) {
        rightborder--;
    }
    for (int i =0; i < rightborder; i++) {
        for (int j = rightborder; j > i; j--) {
            if (arr[i] >=0 && arr[j] >= 0 && arr[i] + arr[j] == value) {
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
        int leftborder = i;
        int rightborder = len;
        while (leftborder < rightborder - 1) {
            int middle = (rightborder + leftborder) / 2;
            if (arr[i] + arr[middle] == value) {
                counter++;
                int temp = middle + 1;
                while (arr[i] + arr[temp] == value && temp < rightborder) {
                    temp++;
                    counter++;
                }
                temp = middle - 1;
                while (arr[i] + arr[temp] == value && temp > leftborder) {
                    temp--;
                    counter++;
                }
                break;
            } else if (arr[i] + arr[middle] > value) {
                rightborder = middle;
            } else {
                leftborder = middle;
            }
        }
    }
    return counter;
}
