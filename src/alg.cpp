// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {        
        for (int j = i + 1; j < len; j++) {            
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
                int duplicates = right - left + 1;
                count += (duplicates * (duplicates - 1)) / 2;
                break;
            } else {
                int countLeft = 1;
                int countRight = 1;
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    countLeft++;
                    left++;
                }
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    countRight++;
                    right--;
                }
                count += countLeft * countRight;
                left++;
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1])
            continue;
        int current = arr[i];
        int target = value - current;
        if (current == target) {
            int currentCount = 0;
            for (int j = i; j < len && arr[j] == current; j++) {
                currentCount++;
            }
            count += (currentCount * (currentCount - 1)) / 2;
        } else {
            int left = i + 1;
            int right = len - 1;
            int firstocr = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    firstocr = mid;
                    right = mid - 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (firstocr != -1) {
                int currentCount = 0;
                for (int j = i; j < len && arr[j] == current; j++) {
                    currentCount++;
                }
                int targetCount = 0;
                for (int j = firstocr; j < len && arr[j] == target; j++) {
                    targetCount++;
                }
                count += currentCount * targetCount;
            }
        }
    }
    return count;
}
