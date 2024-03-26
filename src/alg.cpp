// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int k = 0, j=0;
  while(j<200000) {
    j++;
  }
for (int i = 0; i < len; i++) {
  for (int j = i + 1; j < len; j++) {
    if ((arr[i] + arr[j]) == value) {
        k++;
    }
  }
}
return k;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
  int newlen = len - 1;
  int k = 0;
while (arr[newlen] > value)
  newlen--;
for (int i = 0; arr[i] < newlen; i++)
  for (int j = newlen; i < j; j--)
    if (arr[i] + arr[j] == value)
      k++;
return k;
}
int poisk_binarniy(int* arr, int len2, int dodatok2) {
    int k = 0,a = 0,b = len2 - 1;
  while (a <= b) {
    int sr = a + (b - a) / 2;
    if (arr[sr] == dodatok2) {
      k++;
      int i = sr + 1;
      while (i < len2 && arr[i] == dodatok2) {
        k++;
        i++;
      }
      i = sr - 1;
      while (i >= 0 && arr[i] == dodatok2) {
        k++;
        i--;
      }
      return k;
    }
    else if (arr[sr] > dodatok2)
      b = sr - 1;
    else 
      a = sr + 1;
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
  int k = 0;
for (int i = 0; i < len; i++) {
  int dodatok2 = value - arr[i];
  k = k + poisk_binarniy(&arr[i+1], len - 1 - i, dodatok2);
}
return k;
}
