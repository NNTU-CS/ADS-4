// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
  return 0;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int endl = len - 1;
    do {
        endl = endl - 1;
    } while (arr[endl] > value);
    int i = 0;
    while (i < endl) {
        int j = endl;
        while (j > i) {
            if (arr[j] + arr[i] == value) {
                count++;
            }
            j--;
        }
        i++;
    }
    return count;
  return 0;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int left = i + 1;
        int right = len - 1;
        int sec = value - arr[i];
        while (left <= right) {
            int start = (left + right) / 2;
            if (arr[start] == sec) {
                count++;
                int midlel = start - 1;
                while ((midlel > i) && (arr[midlel] == arr[start])) {
                    count++;
                    midlel--;
                }
                int otr = start + 1;
                while ((i < otr) && (arr[otr] == arr[start])) {
                    count++;
                    otr++;
                }
                break;
                } else if (arr[start] > sec) {
                right = start - 1;
              } else {
              left = start + 1;
            }
        }
    }
    if (count)
        return count;
  return 0;
}
