// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i <= len - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}


int countPairs2(int *arr, int len, int value) {
    int i = 0;
    int j = len - 1;
    int k = 0;
    while (i < j) {
        if (arr[i] + arr[j] > value) {
            j--;
        } else if (arr[i] + arr[j] < value) {
            i++;
        } else if (arr[i] + arr[j] == value) {
            k++;
            j--;
            if (arr[i + 1] == arr[i] && (i + 1 != j) && j != len - 1) {
                k++;
                j++;
                i++;
            }
        }
    }
    return k;
}

int cbinsearch(int *arr, int len, int value) {
    int k = 0;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == value) {
            k++;
            int pup = mid - 1;
            while (pup >= 0 && arr[pup] == value) {
                k++;
                pup--;
            }
            pup = mid + 1;
            while (pup < len && arr[pup] == value) {
                k++;
                pup++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return k;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(&arr[i + 1], len - 1, value - arr[i]);
    }
    return count;
}

