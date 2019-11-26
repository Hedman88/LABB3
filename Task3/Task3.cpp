#include <iostream>

using namespace std;

void swap_sort(int *a, int *b, int *c, bool order);

int main() {
	while (true) {
		int a, b, c;
		int *p1, *p2, *p3;
		bool order;

		cout << "Give a(0 to quit) :" << endl;
		cin >> a;
		p1 = &a;
		if (a == 0) {
			break;
		}
		cout << "Give b :" << endl;
		cin >> b;
		p2 = &b;
		cout << "Give c :" << endl;
		cin >> c;
		p3 = &c;
		cout << "Sort ascending / descending(1 / 0) :" << endl;
		cin >> order;

		swap_sort(p1, p2, p3, order);

		cout << "Result : " << *p1 << " " << *p2 << " " << *p3 << endl;
	}

	return 0;
}

void swap_sort(int *a, int *b, int *c, bool order) {

	if (order) {
		int *k;
		if (*a > *b) {
			k = b;
			b = a;
			a = k;
		}
		if (*b > *c) {
			k = c;
			c = b;
			b = k;
		}
		if (*a > *b) {
			k = b;
			b = a;
			a = k;
		}
	}
	else {
		int *k;
		if (*a < *b) {
			k = b;
			b = a;
			a = k;
		}
		if (*b < *c) {
			k = c;
			c = b;
			b = k;
		}
		if (*a < *b) {
			k = b;
			b = a;
			a = k;
		}
	}

}
