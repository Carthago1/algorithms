#include "algorithms.h"
//Time complexity and memory cost O(NM)
int Levenshtein_distance(std::string& s, std::string& t) {
	int n = s.size(), m = t.size();
	int** a = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		a[i] = new int[m + 1];
	}
	for (int i = 0; i <= n; i++) {
		a[i][0] = i;
	}
	for (int j = 0; j <= m; j++) {
		a[0][j] = j;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i] == t[j]) {
				a[i][j] = std::min(a[i - 1][j] + 1, std::min(a[i][j - 1] + 1, a[i - 1][j - 1]));
			}
			else {
				a[i][j] = std::min(a[i - 1][j] + 1, std::min(a[i][j - 1] + 1, a[i - 1][j - 1] + 1));
			}
		}
	}
	int result = a[n][m];
	for (int i = 0; i <= n; i++) {
		delete[] a[i];
	}
	delete[] a;
	return result;
}