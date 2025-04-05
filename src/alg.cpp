// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for(int i = 0; i < len-1; i++) {
        for(int j = i+1; j < len; j++) {
            if(arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int countPairs2(int *arr, int len, int value) {
        int count = 0;
        int end = len - 1;
        while (end > 0) {
          if (arr[end] > value) {
            end--;
          } else {
            break;
          }
        }
        for (int i = 0; i < len; i++) {
          for (int j = end; j > i; j--) {
            if (arr[i] + arr[j] == value)
              count++;
          }
        }
        return count;
      }
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for(int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if(complement < arr[i]) {
            break;
        }
        int left = i + 1;
        int right = len - 1;
        int first = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == complement) {
                first = mid;
                right = mid - 1;
            }
            else if(arr[mid] < complement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if(first == -1) continue;
        left = first;
        right = len - 1;
        int last = first;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == complement) {
                last = mid;
                left = mid + 1;
            }
            else if(arr[mid] < complement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        count += (last - first + 1);
    }
    return count;
}