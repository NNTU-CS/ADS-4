// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                counter++;
            }
        }
    }
    if (counter == 0)
    return 0;
return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    int end = len - 1;
    while (arr[end] > value) {
        end--;
    }
    for (int lefter = 0; lefter < end; lefter++) {
        for (int righter = end; lefter < righter; righter--) {
            if (arr[lefter] + arr[righter] == value) {
                counter++;
            }
        }
    }
    if (counter == 0)
        return 0;
    return counter;
}
int countPairs3(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        int left = i + 1;
        int right = len - 1;
        int secynd = value - arr[i];
        while (left <= right) {
            int start = (left + right) / 2;
            if (arr[start] == secynd) {
                counter++;
                int midle = start - 1;
                while ((midle > i) && (arr[midle] == arr[start])) {
                    counter++;
                    midle--;
                }
                int otr = start + 1;
                while ((i < otr) && (arr[otr] == arr[start])) {
                    counter++;
                    otr++;
                }
                break;
                } else if (arr[start] > secynd) {
                right = start - 1;
              } else {
              left = start + 1;
            }
        }
    }
    if (counter)
        return counter;
    return 0;
}
