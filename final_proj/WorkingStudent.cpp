#include "WorkingStudent.h"
#include "MA.h"
#include "Practitioner.h"
WorkingStudent::WorkingStudent(char* name, int id, float average, int num_of_courses, char* name_of_teza, int seniority, int weekly_hours) :Person(name, id), Student(name, id, average, num_of_courses),Employee(name,id, seniority), MA(name, id, average, num_of_courses, name_of_teza), Practitioner(name,id,weekly_hours,seniority)
{
}
WorkingStudent::WorkingStudent(WorkingStudent const& w) : Person(w),Employee(w), Student(w), MA(w), Practitioner(w)
{
}
WorkingStudent::~WorkingStudent()
{

}
void WorkingStudent::print()const
{
	cout << "Type: WorkingStudent" << endl;
	cout << "Name: " << name << endl;
	cout << "Id: " << id << endl;
	cout << "Average: " << average << endl;
	cout << "Number of courses: " << num_of_courses << endl;
	cout << "Name of teza: " << name_of_teza << endl;

}
int WorkingStudent::salary()
{//חישוב משכורת מתרגל
	return 1000 + (this->weekly_hours * 100);
}