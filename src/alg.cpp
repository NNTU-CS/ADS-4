// Copyright 2021 NNTU-CS
#include <iostream> 

int countPairs1(int *arr, int len, int value) { 
  int count = 0; 
  for (int i = 0; i < len; i++) { 
    for (int j = i+1; j < len; j++) { 
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) { 
        count++; 
      } 
    } 
  } 
  return count; 
} 

int countPairs2(int *arr, int len, int value) { 
  int count = 0; 
  int right = len - 1; 
  while (right >= 0 && arr[right] > value) { 
    right--; 
  } 
  for (int i = 0; i < right; i++) { 
    for (int j = right; j > i; j--) { 
      if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) { 
        count++; 
      } else if (arr[i] + arr[j] < value) { 
        break; 
      } 
    } 
  } 
  return count; 
} 

int countPairs3(int *arr, int len, int value) { 
  int count = 0; 
  for (int i = 0; i < len - 1; i++) { 
    int left = i + 1; 
    int right = len - 1; 
    while (left < right) { 
      if (arr[i] + arr[left] == value) { 
        count++; 
        left++; 
      } else if (arr[i] + arr[right] == value) { 
        count++; 
        right--; 
      } else if (arr[i] + arr[left] + arr[right] > value) { 
        right--; 
      } else { 
        left++; 
      } 
    } 
  } 
  return count; 
}
