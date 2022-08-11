#include "lip.h"
#include <algorithm>
/*
В массиве a хранится последовательность, в массиве l хранятся наибольшие длины подпоследовательностей,
заверщающихся на элементах с индексом k. Решение за время O(n^2)
*/
int lip(int* a, int* l, int n)
{
    for (int k = 0; k < n; k++) {
        l[k] = 1;
        for (int p = 0; p < k; p++) {
            if (a[k] > a[p]) {
                l[k] = std::max(l[p] + 1, l[k]);
            }
        }
    }
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (l[i] >= l[max]) {
            max = i;
        }
    }
    return  l[max];
}