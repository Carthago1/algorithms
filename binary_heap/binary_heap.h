#ifndef BINARY_HEAP
#define BINARY_HEAP
class binary_heap {
	int* data;
	int size, max_size;
public:
	binary_heap();
	int parent(const int&);
	int left_child(const int&);
	int right_child(const int&);
	void sift_up(int);
	void sift_down(int);
	void insert(int&);
	int extract_max();
	void remove(int);
	void change_priority(int i, int p);
	~binary_heap();
};
#endif