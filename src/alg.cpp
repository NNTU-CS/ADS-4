// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cont = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cont++;
            }
        }
    }
    if (cont == 0)
        return 0;
    return cont;
}

int countPairs2(int *arr, int len, int value) {
    int cont = 0;
    int last = len - 1;
    while (arr[last] > value) {
        last--;
    }
    for (int lefte = 0; lefte < last; lefte++) {
        for (int righte = last; lefte < righte; righte--) {
            if (arr[lefte] + arr[righte] == value) {
                cont++;
            }
        }
    }
    if (cont == 0)
        return 0;
    return cont;
}

int countPairs3(int *arr, int len, int value) {
    int cont = 0;
    for (int i = 0; i < len; ++i) {
        int l = i + 1;
        int r = len - 1;
        int sec = value - arr[i];
        while (l <= r) {
            int first = (l + r) / 2;
            if (arr[first] == sec) {
                cont++;
                int mid = first - 1;
                while ((mid > i) && (arr[mid] == arr[first])) {
                    cont++;
                    mid--;
                }
                int otrez = first + 1;
                while ((i < otrez) && (arr[otrez] == arr[first])) {
                    cont++;
                    otrez++;
                }
                break;
            } else if (arr[first] > sec) {
                r = first - 1;
            } else {
                l = first + 1;
            }
        }
    }
    if (cont)
        return cont;
    return 0;
}
