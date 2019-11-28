#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool initi_data(vector<string> *database) {
	bool sure;
	cout << "Are you sure? (1/0)" << endl;
	cin >> sure;
	if (sure) {
		database->clear();
		return true;
	}
	return false;
}

bool insert(vector<string> *database) {
	while (true) {
		string temp;
		cout << endl << "Give me a name (Q or q to go back)" << endl;
		cin >> temp;
		if (temp == "q" || temp == "Q") {
			break;
		}
		database->push_back(temp);
	}
	return true;
}

const bool search(vector<string> *database) {
	cout << endl << "Give search string" << endl;
	string temp;
	cin >> temp;
	for (int i = 0; i < database->size(); i++) {
		if ((*database)[i].substr(0, temp.length()) == temp) {
			cout << endl << (*database)[i] << endl;
		}
	}
	return true;
}

bool deletef(vector<string> *database) {
	cout << endl << "Delete which name?" << endl;
	string temp;
	cin >> temp;
	for (int i = 0; i < database->size(); i++) {
		if ((*database)[i] == temp) {
			cout << endl << (*database)[i] << " deleted" << endl;
			database->erase(database->begin() + i);
			return true;
		}
	}
	return false;
}

const bool print(vector<string> *database) {
	cout << endl << "Contents:" << endl;
	for (int i = 0; i < database->size(); i++) {
		cout << (*database)[i] << endl;
	}
	return true;
}

const bool save(vector<string> *database) {
	cout << "Filename?" << endl;
	string temp;
	cin >> temp;
	ofstream outfile;
	outfile.open(temp);
	for (int i = 0; i < database->size(); i++) {
		outfile << (*database)[i] << endl;
	}
	outfile.close();
	return true;
}

bool exists(const string temp) {
	ifstream f(temp);
	return f.good();
}

bool load(vector<string> *database) {
	cout << "Enter name of file you want to load." << endl;
	string temp;
	cin >> temp;
	if (exists(temp)) {
		cout << "You will overwrite current database." << endl;
		if (initi_data(database)) {
			ifstream infile;
			infile.open(temp);
			string empty = "";
			string data;
			for (int i = 0;; i++) {
				getline(infile, data); 
				if (data == empty) {
					infile.close();
					return true;
				}
				database->push_back(data);
			}
		}
		else {
			return false;
		}
	}
	else {
		cout << "File doesn't exist" << endl;
		return false;
	}
	return true;
}

void main() {
	int userinput;
	vector<string> *database;
	vector<string> db;
	database = &db;

	while (true) {
		cout << endl << "Menu:" << endl;
		cout << "1: initialise database" << endl;
		cout << "2: insert" << endl;
		cout << "3: search" << endl;
		cout << "4: delete" << endl;
		cout << "5: print" << endl;
		cout << "6: save" << endl;
		cout << "7: load" << endl;
		cout << "8: quit" << endl << endl;

		cout << "Make your choice: ";
		cin >> userinput;
		if (userinput == 1) {
			if (initi_data(database)) {
				cout << endl << "Database Initialised" << endl;
			}
		}
		if (userinput == 2) {
			insert(database);
		}
		if (userinput == 3) {
			search(database);
		}
		if (userinput == 4) {
			deletef(database);
		}
		if (userinput == 5) {
			print(database);
		}
		if (userinput == 6) {
			if (save(database)) {
				cout << "Database saved" << endl;
			}
		}
		if (userinput == 7) {
			if (load(database)) {
				cout << "Database loaded" << endl;
			}
		}
		if (userinput == 8) {
			return;
		}
	}

}