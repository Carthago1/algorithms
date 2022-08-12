#include "algorithms.h"

void merge(int* a, int left, int mid, int right) {
	int* result = new int[right - left];
	int i = left, j = mid, k = 0;
	while (i < mid && j < right) {
		if (a[i] < a[j]) {
			result[k] = a[i];
			i++;
		}
		else {
			result[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < mid) {
		result[k] = a[i];
		i++;
		k++;
	}
	while (j < right) {
		result[k] = a[j];
		j++;
		k++;
	}
	for (int i = left; i < right; i++) {
		a[i] = result[i - left];
	}
	delete[] result;
}

void mergesort(int* a, int left, int right) {
	if (right - left < 2) {
		return;
	}
	int mid = (right + left) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid, right);
	merge(a, left, mid, right);
}