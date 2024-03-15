// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    while (i < len) {
        int j = i + 1;
        while (j < len) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int endl = len - 1;
    do {
        endl = endl - 1;
    } while (arr[endl] > value);
    int i = 0;
    while (i < endl) {
        int j = endl;
        while (j > i) {
            if (arr[j] + arr[i] == value) {
                count++;
            }
            j--;
        }
        i++;
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    while (i < len) {
        int number_of_digits = value - arr[i];
        count = count + cbinsearch(&arr[i + 1], len - i - 1, number_of_digits);
        i++;
    }
    return count;
}
