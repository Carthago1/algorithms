#include "lip.h"
#include <algorithm>
/*
The sequence is in variable a. The array l stores the largest lengths of subsequences,
ending on elements with index k. Time complexity O(n^2)
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