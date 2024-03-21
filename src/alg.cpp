// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                while (left <= right) {
                    int count_left_now = left+1;
                    while (count_left_now <= right) {
                        count++;
                        count_left_now++;
                    }
                    left++;
                }
            } else {
                int countLeft = 1;
                int countRight = 1;
                while (arr[left] == arr[left + 1]) {
                    left++;
                    countLeft++;
                }
                while (arr[right] == arr[right - 1]) {
                    right--;
                    countRight++;
                }
                left++;
                right--;
                if ((countLeft > 1) && (countRight > 1)) {
                    count += countLeft * countRight;
                } else if(countLeft > 1) {
                    count += countLeft;
                } else if (countRight > 1) {
                    count += countRight;
                } else{
                    count++;
                }
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int idx = mid - 1;
            while (idx >= 0 && arr[idx] == value) {
                count++;
                idx--;
            }
            idx = mid + 1;
            while (idx < size && arr[idx] == value) {
                count++;
                idx++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(&arr[i + 1], len - i - 1, value - arr[i]);
    }
    return count;
}
