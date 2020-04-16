#include<iostream>
#include "Header.h"

using namespace std;

int main() {
	int action = 0;

	do {
		cout << "1. Dodaty novu podiju" << endl;
		cout << "2. Dodaty novu categoriu" << endl;
		cout << "3. Peregljanuty podiji" << endl;
		cout << "4. EXIT" << endl;

		cout << endl;

		cout << "Vuberit' diju->_";
		cin >> action;
		cout << endl;

		switch (action) {
		case 1:
			addEventinCategory();
			break;
		case 2:
			addNewCategory();
			break;
		case 3:
			
			ShowEvent();
			break;
		case 4:
			cout << "Bye ;)" << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
	} while (action != 4);

	system("pause");
	return 0;
}