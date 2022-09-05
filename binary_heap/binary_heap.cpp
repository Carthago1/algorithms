#include "binary_heap.h"
#include <cstdlib>
#include <algorithm>

binary_heap::binary_heap():data((int*)calloc(10, sizeof(int))), max_size(10),
size(-1) {}
binary_heap::~binary_heap() {
	free(data);
}
int binary_heap::parent(const int& i) {
	return (i - 1) / 2;
}
int binary_heap::left_child(const int& i) {
	return 2 * i + 1;
}
int binary_heap::right_child(const int& i) {
	return 2 * i + 2;
}
void binary_heap::sift_up(int i) {
	while (i > 0 and data[i] > data[parent(i)]) {
		std::swap(data[i], data[parent(i)]);
		i = parent(i);
	}
}
void binary_heap::sift_down(int i) {
	int max_index = i, l = left_child(i), r = right_child(i);
	if (l <= size and data[max_index] < data[l]) {
		max_index = l;
	}
	if (r <= size and data[max_index] < data[r]) {
		max_index = r;
	}
	if (i != max_index) {
		std::swap(data[i], data[max_index]);
		sift_down(max_index);
	}
}
void binary_heap::insert(int& p) {
	if (size == max_size) {
		max_size *= 1.5;
		int* new_data = (int*)calloc(max_size, sizeof(int));
		for (int i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		free(data);
		data = new_data;
	}
	size += 1;
	data[size] = p;
	sift_up(size);
}
int binary_heap::extract_max() {
	int result = data[0];
	std::swap(data[0], data[size]);
	size -= 1;
	sift_down(0);
	return result;
}
void binary_heap::remove(int i) {
	data[i] = INT32_MAX;
	sift_up(i);
	extract_max();
}
void binary_heap::change_priority(int i, int p) {
	int previous = data[i];
	data[i] = p;
	if (previous < p) {
		sift_up(i);
	}
	else {
		sift_down(i);
	}
}