#include <iostream>

using namespace std;

void replace_chars(char *str, char a, char b);

int main() {

	char str[] = "hello";
	char a[] = "l";
	char b[] = "w";

	cout << str << endl;
	replace_chars(str, *a, *b);
	cout << str << endl;

	system("pause");
	return 0;
}

void replace_chars(char *str, char a, char b) {
	char k[] = "\0";
	for (int i = 0;; i++) {
		if (*(str + i) == a) {
			*(str + i) = b;
		}
		if (*(str + i) == *k) {
			return;
		}
	}
}