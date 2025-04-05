// Copyright 2021 NNTU-CS
void ssort(int* array, int left, int right) {
    if (left < right) {
        int pivot = array[left + (right - left) / 2];
        int l = left, r = right;
        while (l <= r) {
            while (array[l] < pivot) l++;
            while (array[r] > pivot) r--;
            if (l <= r) {
                int temp = array[l];
                array[l] = array[r];
                array[r] = temp;
                l++;
                r--;
            }
        }
        ssort(array, left, r);
        ssort(array, l, right);
    }
}

int countPairs1(int *array, int len, int value) {
    ssort(array, 0, len - 1);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && array[i] == array[i - 1]) continue;
        for (int j = i + 1; j < len; j++) {
            if (j > i + 1 && array[j] == array[j - 1]) continue;
            if (array[i] + array[j] == value) {
                count++;
                break;
            } else if (array[i] + array[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *array, int len, int value) {
    ssort(array, 0, len - 1);
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = array[left] + array[right];
        if (sum == value) {
            count++;
            int l = array[left];
            int r = array[right];
            while (left < right && array[left] == l) left++;
            while (left < right && array[right] == r) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *array, int len, int value) {
    ssort(array, 0, len - 1);
    int count = 0;
    int l = 0, r = len - 1;

    while (l < r) {
        int sum = array[l] + array[r];
        if (sum == value) {
            count++;
            l++;
            r--;
            while (l < r && array[l] == array[l - 1]) l++;
            while (l < r && array[r] == array[r + 1]) r--;
        } else if (sum < value) {
            l++;
        } else {
            r--;
        }
    }
    return count;
}
