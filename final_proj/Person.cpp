#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
#include <string.h>
using namespace std;
Person::Person(char* name, long id)
{//בנאי
	this->name = new char[strlen(name) + 1];//הקצאה מדוייקת לשם
	strcpy(this->name, name);
	this->id = id;
	total_person++;
}
Person::Person(const Person& p)
{//בנאי מעתיק
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	id = p.id;
	total_person++;
}
void  Person::print() const
{//הדפסה מסודרת של האובייקט
	cout << "Type: Person " << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
}
Person::~Person()
{//פונקציה הורסת
	delete[] name;//שחרור זיכרון
	total_person--;
}
void Person::print_static()
{
	cout << "Number Of Person: " << total_person<<endl;
}
