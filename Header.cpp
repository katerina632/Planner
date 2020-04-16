#include "Header.h"
#include"windows.h"
#include <iostream>

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int index_count = 0;

list<Categoria> listCategory;

int id = 1;

void addNewCategory()
{
	Categoria newCategory;
	cout << "Vvedit' nazvy categoriji ->_";
	cin >> newCategory.name;
	newCategory.id = id;
	id++;
	listCategory.push_back(newCategory);
	cout << endl;
}

void addEventinCategory()
{
	if (listCategory.empty()) {

		cout << "Dodajte spershu hoch odnu categoriju!" << endl << endl;
		return;
	}
	else {
		int idCategory;
		bool isFound = false;

		for (Categoria item : listCategory) {
			cout << item.id << ") " << item.name << endl;
		}
		cout << endl;
		cout << "Vuberit' nomer categoriji->_ ";
		cin >> idCategory;
		for (Categoria& item : listCategory) {
			if (item.id == idCategory) {
				isFound = true;

				Podia newPodia;

				cout << "Vvedit' nazvy podij ->_";
				cin >> newPodia.nazva;

				cout << "Vvedit' opys podij ->_";
				cin.ignore();
				getline(cin, newPodia.opys);

				cout << " Vvedit' datu podij (u formati: DD MM RR)->_";
				cin >> newPodia.NewDate.Day;
				cin >> newPodia.NewDate.Month;
				cin >> newPodia.NewDate.Year;

				cout << "Vvedit' chas podij ->_";
				cin >> newPodia.time;
				do {
					cout << "Vvedit' riven' vazhlyvosti podijj ->_";
					cin >> newPodia.RivenVazhlyvosti;
					if (newPodia.RivenVazhlyvosti < 1 || newPodia.RivenVazhlyvosti>3) {
						cout << endl;
						cout << "Vvedit' znachennja vid 1 do 3!" << endl;
						cout << endl;
					}
				} while (newPodia.RivenVazhlyvosti < 1 || newPodia.RivenVazhlyvosti>3);

				item.listPodij.push_back(newPodia);
				cout << endl;
			}
			
		}
		if (isFound == false) {
			cout << "Takoji katerogiji ne znajdeno!" << endl;
		}
	}
}

void ShowEvent()
{
	if (listCategory.empty()) {

		cout << "Spysok podij pustyj!" << endl << endl;
		return;
	}
	else {
		int count = 1;

		for (Categoria& item : listCategory) {
			cout << item.id << ".Kategorija - " << item.name << ": " << endl;
			sort();
			for (Podia& item2 : item.listPodij) {
				switch (item2.RivenVazhlyvosti) {
				case 1:
					SetConsoleTextAttribute(color, FOREGROUND_GREEN);

					cout << count << ") " << item2.nazva << " - " <<
						item2.NewDate.Day << "." << item2.NewDate.Month <<
						"." << item2.NewDate.Year << " O " << item2.time <<
						"\n\t" << item2.opys << endl;

					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					break;
					
				case 2:
					SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);

					cout << count << ") " << item2.nazva << " - " <<
						item2.NewDate.Day << "." << item2.NewDate.Month <<
						"." << item2.NewDate.Year << " O " << item2.time <<
						"\n\t" << item2.opys << endl;
					

					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					break;

				case 3:
					SetConsoleTextAttribute(color, FOREGROUND_RED);

					cout << count << ") " << item2.nazva << " - " <<
						item2.NewDate.Day << "." << item2.NewDate.Month <<
						"." << item2.NewDate.Year << " O " << item2.time <<
						"\n\t" << item2.opys << endl;
				

					SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					break;
				}
				count++;
			}
			count = 1;
		}
		cout << endl;
	}
}

void sort()
{	
	for (Categoria &item : listCategory) {

		item.listPodij.sort(comp);	
	}	
}

bool comp(Podia a, Podia b)
{
	if (a.NewDate.Year > b.NewDate.Year ||
		a.NewDate.Year == b.NewDate.Year &&
		a.NewDate.Month > b.NewDate.Month ||
		a.NewDate.Year == b.NewDate.Year &&
		a.NewDate.Month == b.NewDate.Month &&
		a.NewDate.Day > b.NewDate.Day) {

		return  false;
	}	
}

