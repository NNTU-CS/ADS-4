// Copyright 2021 NNTU-CS

int main() {
int arr[] = { 20, 30, 30, 40, 40 };
int len = sizeof(arr) / sizeof(arr[0]);
int value = 50;
countPairs1(arr, len, value);
countPairs2(arr, len, value);
countPairs3(arr, len, value);
return 0;
}
