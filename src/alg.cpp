// Copyright 2025 NNTU-CS

void quickSort(int* arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[left + (right - left) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int countPairs1(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < len; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            if (arr[i] + arr[j] == value) {
                count++;
                break;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            int lval = arr[left];
            int rval = arr[right];
            while (left < right && arr[left] == lval) left++;
            while (left < right && arr[right] == rval) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    quickSort(arr, 0, len - 1);
    int count = 0;
    const int MAX = 10000;
    char used[MAX] = {0};
    char visited[MAX] = {0};

    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        if (complement >= 0 && complement < MAX &&
            visited[complement] && !used[arr[i]] && !used[complement]) {
            count++;
            used[arr[i]] = 1;
            used[complement] = 1;
        }
        visited[arr[i]] = 1;
    }
    return count;
}

