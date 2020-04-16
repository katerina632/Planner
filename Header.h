#pragma once
#include <string>
#include <list>
using namespace std;

struct Date {
	int index;
	int Day;
	int Month;
	int Year;
};
struct  Podia {
	string nazva;
	string opys;
	Date NewDate;
	string time;
	int RivenVazhlyvosti;
};


struct Categoria {
	int id;
	string name;
	list<Podia> listPodij;
};

void addNewCategory();
void addEventinCategory();

void ShowEvent();
void sort();

bool comp(Podia a, Podia b);