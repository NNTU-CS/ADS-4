// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
	int col = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] + arr[j] == value) {
				col++;
			}
		}
	}
	return col;
}
int countPairs2(int *arr, int len, int value) {
	int col = 0;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j > i; j--) {
			if (arr[i] + arr[j] == value) {
				col++;
			}
		}
	}
	return col;
}
int countPairs3(int *arr, int len, int value) {
	int col = 0;
	for (int i = 0; i < len; i++) {
		int other = value - arr[i];
		int left = i + 1;
		int right = len - 1;
		int first = -1, last = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] >= other) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		first = (left < len && arr[left] == other) ? left : -1;
		if (first != -1) {
			right = len - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (arr[mid] <= other) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
			last = right;
			col += (last - first + 1);
		}
	}
	return col;
}
