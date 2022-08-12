#include "algorithms.h"

//Finding the longest subsegment with sum no more than M. All numbers in the segment >= 0

int subsegment(int* a, int n, int m)
{
    int s = 0, r = 0, max_length = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && a[r] + s <= m) {
            s += a[r++];
        }
        if (r - l > max_length) {
            max_length = r - l;
        }
        s -= a[l];
    }
    return max_length;
}