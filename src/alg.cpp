// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
                while (j + 1 < len && arr[j] == arr[j + 1]) {
                    j++;
                }
            }
        }
    }

    return count;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            // Проверка следующих элементов, чтобы избежать повторений
            while (left < right && arr[left] == arr[left + 1]) {
                left++;
            }
            while (left < right && arr[right] == arr[right - 1]) {
                right--;
            }
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
  if (len < 2) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int complement = value - arr[i];
        int left = i + 1, right = len - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] == complement) {
                count++;
                break;  
            } else if (arr[middle] < complement) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }

    return count;
  return 0;
}
