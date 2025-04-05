// Copyright 2021 NNTU-CS
int countPairs1(int *data, int size, int target) {
    int result = 0;
    for (int first = 0; first < size - 1; first++) {
        for (int second = first + 1; second < size; second++) {
            if (data[first] + data[second] == target) {
                result++;
            }
        }
    }
    return result;
}
int countPairs2(int *array, int length, int sum) {
    int pairs = 0;
    int high = length - 1;
    
    while (high > 0 && array[high] > sum) {
        high--;
    }
    for (int low = 0; low < high; low++) {
        int current = array[low];
        int needed = sum - current;
        
        int left = low + 1;
        int right = high;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] == needed) {
                pairs++;
                int temp = mid - 1;
                while (temp >= left && array[temp] == needed) {
                    pairs++;
                    temp--;
                }
                temp = mid + 1;
                while (temp <= right && array[temp] == needed) {
                    pairs++;
                    temp++;
                }
                break;
            } else if (array[mid] < needed) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return pairs;
}
int findMatches(int *numbers, int start, int end, int match) {
    int first = -1;
    int low = start;
    int high = end;

    while (low <= high) {
        int center = low + (high - low) / 2;
        if (numbers[center] >= match) {
            if (numbers[center] == match) first = center;
            high = center - 1;
        } else {
            low = center + 1;
        }
    }
    if (first == -1) return 0;
    int last = first;
    low = first;
    high = end;
    while (low <= high) {
        int center = low + (high - low) / 2;
        if (numbers[center] <= match) {
            if (numbers[center] == match) last = center;
            low = center + 1;
        } else {
            high = center - 1;
        }
    }
    return last - first + 1;
}
int countPairs3(int *elements, int count, int total) {
    int found = 0;
    for (int index = 0; index < count; index++) {
        int complement = total - elements[index];
        if (complement < 0) continue;
        found += findMatches(elements, index + 1, count - 1, complement);
    }
    return found;
}
