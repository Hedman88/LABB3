#include <iostream>

using namespace std;

void swap_sort(int *a, int *b, int *c, bool order);

int main() {
	while (true) {
		int a, b, c;
		bool order;

		cout << "Give a(0 to quit) :" << endl;
		cin >> a;
		if (a == 0) {
			break;
		}
		cout << "Give b :" << endl;
		cin >> b;
		cout << "Give c :" << endl;
		cin >> c;
		cout << "Sort ascending / descending(1 / 0) :" << endl;
		cin >> order;

		swap_sort(&a, &b, &c, order);

		cout << "Result : " << a << " " << b << " " << c << endl;
	}

	return 0;
}

void swap_sort(int *a, int *b, int *c, bool order) {

	if (order) {
		int k;
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
		int k;
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
