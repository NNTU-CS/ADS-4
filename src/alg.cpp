// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int cnt = 0;
for (int m = 0; m < len-1; m++) {
for (int n = m + 1; n < len; ++n) {
if (arr[m] + arr[n] == value) {
cnt++;
}
}
}
return cnt;
}
int skipDuplicates(int* arr, int len, int index, int direction) {
int current = index;
while (current >= 0 && current < len && arr[current] == arr[index]) {
current += direction;
}
return current;
}
int countPairs2(int *arr, int len, int value) {
int cnt = 0;
int right = len - 1;
int left = 0;
while (left < right) {
int sum = arr[left] + arr[right];
if (sum == value) {
cnt++;
left = skipDuplicates(arr, len, left, 1);
right = skipDuplicates(arr, len, right, -1);
} else if (sum < value) {
left++;
} else {
right--;
}
}
return cnt;
}
int countPairs3(int *arr, int len, int value) {
int cnt = 0;
for (int i = 0; i < len; ++i) {
int target = value - arr[i];
int left = i + 1;
int right = len - 1;
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] == target) { 
cnt++;
while (mid + 1 < len && arr[mid] == arr[mid + 1]) {
mid++;
}
break; 
} else if (arr[mid] < target) {
left = mid + 1;
} else {
right = mid - 1;
}
}
while (i + 1 < len && arr[i] == arr[i + 1]) {
i++;
}
}
return cnt;
}
