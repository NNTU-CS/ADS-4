// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++)  {
			if ((arr[i] + arr[j]) == value) count++;
		}
	}
	return count;
}
int countPairs2(int* arr, int len, int value) {
	int count = 0;
	int endl = len - 1;
	while (arr[endl] > value) {
		endl--;
	}
	for (int i = 0; i < endl; i++) {
		for (int j = endl; i < j; j--) {
			if ((arr[i] + arr[j]) == value) count++;
		}
	}
	return count;
}
int countPairs3(int* arr, int len, int value) {
	int endl = len - 1;
	int count = 0;
	while (arr[endl] > value) endl--;
	for (int i = 0; i < endl; i++) {
		for (int j = endl; i < j; j--) {
			if (((arr[i] + arr[j]) == value) && (arr[i] >= 0 && arr[j] >= 0)) {
				count++;
			}
		}
	}
	return count;
}
