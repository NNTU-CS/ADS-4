// Copyright 2021 NNTU-CS
int countPairs3(int* arr, int len, int value);
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    int r = len - 1;
    while (arr[r] >= value)
        r--;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value)
                count++;
    }
    if (count)
        return count;
return 0;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int end = len - 1;
    int g = value - arr[0];
    while (arr[end] >= value)
        end--;
return countPairs3(arr, len, value);
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int x, left, right, mid;
    for (int i = 0; i < len; i++) {
    left = i + 1;
    right = len - 1;
    x = value - arr[i];
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            count++;
            int min = mid - 1;
            int max = mid + 1;
            while ((arr[mid] == arr[min]) && min > i) {
                count++;
                min--;
            }
            while ((arr[mid] == arr[max]) && max > i) {
                count++;
                max++;
            }
            break;
        }
    }
    }
    if (count)
        return count;
return 0;
}
