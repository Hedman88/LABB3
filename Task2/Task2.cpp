#include <iostream>

using namespace std;

int average_salary(const int *a, int b);

int main() {

	int employees;
	cout << "How many employees are there?" << endl;
	cin >> employees;
	int *salaries = new int[employees];
	for (int i = 0; i < employees; i++) {
		cout << "What is employee nr " << i+1 << "'s salary?" << endl;
		cin >> *(salaries + i);
	}

	int output = average_salary(salaries, employees);

	cout << "The average salary is: " << output << " amount of currency." << endl;

	delete[] salaries;

	system("pause");
	return 0;
}

int average_salary(const int *a, int b) {
	int average = 0;
	for (int i = 0; i < b; i++) {
		average = average + a[i];
	}
	average = average / b;
	return average;
}
