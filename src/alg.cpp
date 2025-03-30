// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int count1 = 0;
for (int i = 0; i < len; ++i) {
for (int j = i + 1; j < len; ++j) {
if (arr[i] + arr[j] == value) {
count1++;
}
}
}
return count1;
}
int countPairs2(int* arr, int len, int value) {
int count2 = 0;
int left = 0, right = len - 1;
while (left < right) {
int sum = arr[left] + arr[right];
if (sum == value) {
int leftCount = 1;
int rightCount = 1;
while (left + 1 < right && arr[left] == arr[left + 1]) {
leftCount++;
left++;
}
while (right - 1 > left && arr[right] == arr[right - 1]) {
rightCount++;
right--;
}
count2 += leftCount * rightCount;
left++;
right--;
} else if (sum < value) {
left++;
} else {
right--;
}
}
return count2;
}
int binarySearch(int* arr, int left, int right, int value) {
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] == value) {
return mid;
} else if (arr[mid] < value) {
left = mid + 1;
} else {
right = mid - 1;
}
}
return -1;
}
int countPairs3(int* arr, int len, int value) {
int count3 = 0;
for (int i = 0; i < len; ++i) {
int target = value - arr[i];
int idx = binarySearch(arr, i + 1, len - 1, target);
if (idx != -1) {
count3++;		
int left = idx - 1;
while (left > i && arr[left] == target) {
count3++;
left--;
}
int right = idx + 1;
while (right < len && arr[right] == target) {
count3++;
right++;
}
}
}
return count3;
}
