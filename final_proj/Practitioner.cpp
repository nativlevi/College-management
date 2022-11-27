#include "Practitioner.h"
Practitioner::Practitioner(char* name, long id, int weekly_hours, int seniority) :Person(name,id), Employee(name, id, seniority)
{
	this->weekly_hours = weekly_hours;
}
void Practitioner::print()const
{
	cout << "Type:Practitioner" << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Seniority: " << seniority << endl;
	cout << "Weekly hours: " << weekly_hours << endl;
}
Practitioner::~Practitioner()
{//פונקציה הורסת
}

int Practitioner::salary()
{//חישוב משכורת מתרגל
	return 1000 + (this->weekly_hours * 100) + (this->seniority * 200);
}
