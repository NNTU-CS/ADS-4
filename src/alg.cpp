#include "math.h"
#include <iostream>
#include <math.h>
#include <vector>
// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
    int sum = 0, j = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                sum++;
            };
        }
    }
    return sum;
}

int countPairs2(int* arr, int len, int value)
{
    int sum = 0;
    for ( int j = len - 1; j > 0; --j) {
        if (arr[j] > value) {
            continue;
        }
        for (int i = 0; i < j; ++i) {

            if (arr[j] + arr[i] == value) {
                sum++;
            }
        }
    }
    return sum;

}

int pointCalc(int current_value, int searching_value_part, int point_index, int precision, int size) {
    if ((current_value > searching_value_part) && ((point_index - precision) <= size)) {
        point_index -= precision;

    }
    else if ((current_value < searching_value_part) && ((point_index + precision) >= size)) {
        point_index += precision;
    }
    return point_index;
}
int countPairs3(int* arr, int len, int searching_value_summ) {

    int amount = 0;
    int iterations = int(sqrt(len));

    for (int a = 0; a < len; a++) {
        std::vector<int> arr_vect(arr, arr + len);

        if (arr[a] > searching_value_summ) {
            continue;
        }

        int precision = (len) / 2;
        int point_index = precision;
        int searching_value_part = searching_value_summ-arr_vect.at(a);

        for (int i = 0; i < iterations; i++) {
            int max_index = arr_vect.size() - 1;
            if (point_index > max_index) {
                point_index = max_index;
            }
            else if (point_index < 0) {
                point_index = 0;
            }
            precision /= 2;
            int current_value = arr_vect.at(point_index);
            if (current_value == searching_value_part) {
                amount++;
            }
            point_index = pointCalc(current_value, searching_value_part, point_index, precision, max_index);
        }
    }
    return amount;
}

