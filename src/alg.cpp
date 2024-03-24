// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i <= len-1; i++) {
        for (int j = i + 1; j <= len; j++) {
            if (arr[i] +arr[j] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int j = len-1, counter = 0;
    while (arr[j] > value) {
        j--;
    }
    for (int i = 0; i < j; i++) {
        for (int t = j; t > i; t--) {
            if (arr[t] + arr[i] == value) {
                counter++;
            }
        }
    }
    return counter;
}
int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int lowg = 0;
    int highg = size-1;

    while (lowg <= highg) {
        int mid = (lowg+highg)/2;
        if (arr[mid] < value) {
            lowg = mid + 1;
        } else if (arr[mid] > value) {
            highg = mid-1;
        } else {
            count++;
            int arg1 = mid-1;
            mid++;
            while (arr[mid] == value) {
                count++;
                mid++;
            }
            while (arr[arg1] == value) {
                count++;
                arg1--;
            }
            break;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int i = 0;
    int count = 0;
    while (arr[i] <= (value / 2)-1) {
        int promznach = value - arr[i];
        count += cbinsearch(arr, len, promznach);
        i++;
    }
    int mid = cbinsearch(arr, len, value / 2);
    count += mid * (mid - 1) / 2;
    return count;
}
