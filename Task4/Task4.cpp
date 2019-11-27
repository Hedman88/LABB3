#include <iostream>

using namespace std;

void swap_sort(int **a, int **b, int **c, bool order);

int main() {
	int a = 7, b = 6, c = 1;
	int *p1 = &a, *p2 = &b, *p3 = &c;
	swap_sort(&p1, &p2, &p3, true);
	cout << *p1 << " " << *p2 << " " << *p3;

	system("pause");
	return 0;
}

void swap_sort(int **a, int **b, int **c, bool order) {

	if (order) {
		int *k;
		if (*a > *b) {
			k = *b;
			*b = *a;
			*a = k;
		}
		if (*b > *c) {
			k = *c;
			*c = *b;
			*b = k;
		}
		if (*a > *b) {
			k = *b;
			*b = *a;
			*a = k;
		}
	}
	else {
		int *k;
		if (*a < *b) {
			k = *b;
			*b = *a;
			*a = k;
		}
		if (*b < *c) {
			k = *c;
			*c = *b;
			*b = k;
		}
		if (*a < *b) {
			k = *b;
			*b = *a;
			*a = k;
		}
	}
}
