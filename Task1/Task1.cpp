#include <iostream>

using namespace std;

int strlen(char *p);

int main() {
	char arr[] = "computer";
	char *ptr = arr;
	int length = strlen(ptr);
	cout << length << endl;

	system("pause");
	return 0;
}

int strlen(char *p) {
	char checker[] = "\0";
	for (int i = 0;; i++) {
		if (*(p + i) == *checker) {
			return i;
		}
	}
}