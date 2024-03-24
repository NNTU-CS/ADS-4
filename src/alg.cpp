// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((*(arr + i) + *(arr + j)) == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int rightborder = len - 1;
    for (int i = 0; i < rightborder; i++) {
        for (int j = rightborder; j > i; j--) {
            if ((*(arr + i) + *(arr + j)) > value) {
                rightborder--;
            } else if ((*(arr + i) + *(arr + j)) == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int c = 0; c < len - 1; c++) {
        int leftborder = c;
        int rightborder = len;
        while (leftborder < rightborder - 1) {
            int center = (leftborder + rightborder) / 2;
            if ((*(arr + c) + *(arr + center)) == value) {
                count++;
                int i = center - 1;
                while ((*(arr + c) + *(arr + (i))) == value && i > leftborder) {
                    count++;
                    i--;
                }
                int j = center + 1;
                while (*(arr + c) + *(arr + (j)) == value && j < rightborder) {
                    count++;
                    j++;
                }
                break;
            } else if ((*(arr + c) + *(arr + center)) < value) {
                leftborder = center;
            } else {
                rightborder = center;
            }
        }
    }
    return count;
}
