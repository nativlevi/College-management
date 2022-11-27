#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Data.h"
Data::Data()
{//בנאי דיפולטיבי
	arr = NULL;
	size = 0;
}
Data::~Data()
{//פונקציה הורסת 
	for (int i = 0; i < size; i++)
	{
		delete arr[i];//מחיקת מצביע נוכחי
	}
	delete[] arr;//מחיקת המצביע למערך האובייקטים
}
void Data::operator+=(Person* p)
{//הוספת אדם למאגר
	if (size == 0)
	{//במידה והמאגר ריק
		arr = new Person * [1];//הקצאת מקום אחד
		arr[size] = p;//הוספת האדם שקיבלנו
		size++;
		return;//סיום הפונקציה
	}
	Person** temp = new Person * [size];//הגדרת מערך בגודל שיש לנו לשמירת הערכים
	int i;//אינדקס
	for (i = 0; i < size; i++)
	{
		temp[i] = arr[i];//העתקת האנשים שקיימים כבר במאגר
	}
	delete[]arr;//מחיקת המצביע למערך של המאגר
	arr = new Person * [size + 1];//הקצאה בגודל המדוייק החדש
	for (i = 0; i < size; i++)
	{
		arr[i] = temp[i];//החזרת הערכים ששמרנו בtemp 
	}
	arr[size] = p;//הוספת האובייקט שקיבלנו
	delete[]temp;//מחיקת מצביע עזר
	size++;//עדכון הגודל החדש
	return;//סיום הפונקציה
}
void Data::print_all()const
{//הדפסת המאגר
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i]->print();//זימון פונקציות ההדפסה בהתאם לסוג האובייקט
		if (dynamic_cast <Employee*>(arr[i]))
		{
			cout << "Salary: " << dynamic_cast <Employee*>(arr[i])->salary() << endl;//הדפסת משכורת
		}
		cout << "~~~~~~~~~~~~~~~~~~" << endl;
	}
}
bool Data::find(int long id)
{//חיפוש אובייקט במאגר הקיים
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->get_id() == id)//אם התעודת זהות שקיבלנו זהה לתעודת זהות של האובייקט
			return true;//מצאנו אובייקט זהה
	}
	return false;//אין אדם כזה במאגר
}
void Data::init()
{
	int choise; //בחירת סוג מתאים מהתפריט
	char name[20]; //מערך סטטי לקליטת שם
	long id; //תעודת זהות
	int seniority;//ניסיון
	float average = 0.0; //ממוצע
	long phone_num;//מספר טלפון של מזכירה
	int extra_hours;//שעות נוספות של אב בית
	int num_of_courses;//מספר קורסים של מרצה
	int weekly_hours;//שעות שבועיות של מתרגל
	char name_of_teza[30];//שם טזה
	Person* p;//מצביע עזר
	int work_hours;//שעות עבודה של המנקה
	char nameofdepartment[30];//מחלקה


	cout << "Please enter:" << endl;//הדפסת תפריט
	cout << "1-Student" << endl;
	cout << "2-Employee" << endl;
	cout << "3-Working Student" << endl;
	cout << "0-EXIT" << endl;

	cin >> choise;
	int choise2;//משתנה לשמירת הבחירת השנייה

	while (choise)//כל עוד לא נקלט 0
	{
		switch (choise)//בחירת הטיפוס המתאים
		{
		case 1://Student
			cout << "Please enter:" << endl;
			cout << "1-BA Student" << endl;
			cout << "2-MA Student" << endl;

			cin >> choise2;

			switch (choise2)
			{
			case 1://BA Strudent
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "ID: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{//בדיקה שתעודת הזהות לא חוזרת על עצמה 
					cout << "ID exist, try again " << endl;
					cin >> id;
				}
				cout << "Average: ";
				cin >> average;
				while (average < 0 || average>100)
				{//תקינות ממוצע
					cout << "Average must be between 0-100. Please enter new average:" << endl;
					cin >> average;
				}
				cout << endl;
				cout << "Number Of Courses: ";
				cin >> num_of_courses;
				while (num_of_courses < 0)
				{//תקינות מספר קורסים
					cout << "Number of courses must be positive. Please enter new number of courses: " << endl;
					cin >> num_of_courses;
				}
				cout << endl;
				cout << "Name Of Department: ";
				cin >> nameofdepartment;
				p = new BA(name, id, average, num_of_courses, nameofdepartment);
				Data::operator+=(p);
				break;
			case 2://MA Student
				cout << "Please enter: " << endl;;
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "ID: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{
					cout << "Id excist. try again" << endl;
					cin >> id;
				}
				cout << "Average: ";
				cin >> average;
				while (average < 0 || average>100)
				{//תקינות ממוצע
					cout << "Average must be between 0-100. Please enter new average:" << endl;
					cin >> average;
				}
				cout << endl;
				cout << "Number of courses: ";
				cin >> num_of_courses;
				while (num_of_courses < 0)
				{//תקינות מספר קורסים
					cout << "Number of courses must be positive. Please enter new number of courses: " << endl;
					cin >> num_of_courses;
				}
				cout << endl;
				cout << "Name of teza: ";
				cin >> name_of_teza;
				cout << endl;
				p = new MA(name, id, average, num_of_courses, name_of_teza);
				Data::operator+=(p);
				break;
			default:
				cout << "Wrong input" << endl;
				break;
			}
			break;
		case 2://Employee
			cout << "Please enter:" << endl;
			cout << "1 - Practitioner Employee" << endl;
			cout << "2 - Cleaner Employee" << endl;
			cout << "3 - House Keeper Employee" << endl;
			cout << "4 - Secretary Employee" << endl;
			cout << "5 - Lecturer Employee" << endl;

			cin >> choise2;
			switch (choise2)
			{
			case 1:// Practitioner
				cout << "please enter" << endl;
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "id: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{
					cout << "ID exist, try again" << endl;
					cin >> id;
				}
				cout << "seniority: ";
				cin >> seniority;
				while (seniority < 0)
				{
					cout << "Seniority must be positive. Pleease enter again: " << endl;
					cin >> seniority;
				}
				cout << endl;
				cout << "Weekly hours: ";
				cin >> weekly_hours;
				while (weekly_hours < 0)
				{
					cout << "Number of hourse must be positive. Pleease enter new number of weekly hours: " << endl;
					cin >> weekly_hours;
				}
				cout << endl;
				p = new Practitioner(name, id, weekly_hours, seniority);
				Data::operator+=(p);
				break;
			case 2:// Cleaner
				cout << "please enter" << endl;
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "id: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{
					cout << "ID exist, try again" << endl;
					cin >> id;
				}
				cout << "seniority: ";
				cin >> seniority;
				while (seniority < 0)
				{
					cout << "Seniority must be positive. Pleease enter again: " << endl;
					cin >> seniority;
				}
				cout << endl;
				cout << "Work hours: ";
				cin >> work_hours;
				while (work_hours < 0)
				{
					cout << "Number of hourse must be positive. Pleease enter new number of work hours: " << endl;
					cin >> work_hours;
				}
				cout << endl;
				p = new Cleaner(name, id, seniority, work_hours);
				Data::operator+=(p);
				break;
			case 3:// House Keeper
				cout << "please enter" << endl;
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "id: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{
					cout << "ID exist, try again" << endl;
					cin >> id;
				}
				cout << "seniority: ";
				cin >> seniority;
				while (seniority < 0)
				{
					cout << "Seniority must be positive. Pleease enter again: " << endl;
					cin >> seniority;
				}
				cout << endl;
				cout << "Extra hours: ";
				cin >> extra_hours;
				while (extra_hours < 0)
				{
					cout << "Seniority must be positive. Pleease enter again: " << endl;
					cin >> extra_hours;
				}
				cout << endl;
				p = new HouseKeeper(name, id, seniority, extra_hours);
				Data::operator+=(p);
				break;
			case 4:// Secretary
				cout << "please enter" << endl;
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "id: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{
					cout << "ID exist, try again" << endl;
					cin >> id;
				}
				cout << "seniority: ";
				cin >> seniority;
				while (seniority < 0)
				{
					cout << "Seniority must be positive. Pleease enter again: " << endl;
					cin >> seniority;
				}
				cout << endl;
				cout << "Phone num: ";
				cin >> phone_num;
				cout << endl;
				p = new Secretary(name, id, seniority, phone_num);
				Data::operator+=(p);
				break;

			case 5:// Lecturer
				cout << "please enter" << endl;
				cout << "Name: ";
				cin >> name;
				cout << endl;
				cout << "id: ";
				cin >> id;
				cout << endl;
				while (find(id))
				{
					cout << "ID exist, try again" << endl;
					cin >> id;
				}
				cout << "seniority: ";
				cin >> seniority;
				while (seniority < 0)
				{
					cout << "Seniority must be positive. Pleease enter again: " << endl;
					cin >> seniority;
				}
				cout << endl;
				cout << "Number of courses: ";
				cin >> num_of_courses;
				while (num_of_courses < 0)
				{//תקינות מספר קורסים
					cout << "Number of courses must be positive. Please enter new number of courses: " << endl;
					cin >> average;
				}
				cout << endl;
				p = new Lecture(name, id, seniority, num_of_courses);
				Data::operator+=(p);
				break;
			default:
				cout << "Wrong input!" << endl;
				break;
			}
			break;
		case 3://Working Student
			cout << "Name: " << endl;
			cin >> name;
			cout << "ID: " << endl;
			cin >> id;
			while (find(id))
			{//בדיקה שתעודת הזהות לא חוזרת על עצמה 
				cout << "ID exist, try again " << endl;
				cin >> id;
			}
			cout << "Average: " << endl;
			cin >> average;
			while (average < 0 || average>100)
			{//תקינות ממוצע
				cout << "Average must be between 0-100. Please enter new average: " << endl;
				cin >> average;
			}
			cout << endl;
			cout << "Number of courses: " << endl;
			cin >> num_of_courses;
			while (num_of_courses < 0)
			{//תקינות מספר קורסים
				cout << "Number of courses must be positive. Please enter new number of courses: " << endl;
				cin >> average;
			}
			cout << endl;
			cout << "Name of teza: ";
			cin >> name_of_teza;
			cout << endl;
			cout << "weekly_hours: ";
			cin >> weekly_hours;
			while (weekly_hours < 0)
			{
				cout << "Number of hourse must be positive. Pleease enter new number of weekly hours: " << endl;
				cin >> weekly_hours;
			}
			cout << endl;
			cout << "seniority: ";
			cin >> seniority;
			while (seniority < 0)
			{
				cout << "Seniority must be positive. Pleease enter again: " << endl;
				cin >> seniority;
			}
			cout << endl;
			p = new WorkingStudent(name, id, average, num_of_courses, name_of_teza, seniority, weekly_hours);
			Data::operator+=(p);
			break;
		default:
			cout << "Wrong input! Please enter your choice again " << endl;
			break;
		}//end of switch
		cout << "Please enter:" << endl;
		cout << "1-Student" << endl;
		cout << "2-Employee" << endl;
		cout << "3-Working Student" << endl;
		cout << "0-EXIT" << endl;
		cin >> choise;//קליטה מחדש
	}
	return;
}
void Data::search(long id)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->get_id() == id)
		{
			cout << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << "This id was found on the list. Details of person:" << endl;
			arr[i]->print();
			cout << "~~~~~~~~~~~~~~~~~~" << endl;
			return;
		}
	}
	cout << "ID was not found on the list." << endl;
}
void Data::operator-=(long id)
{
	if (!arr)
	{
		cout << "The list is empty" << endl;
		return;
	}
	if(find(id))
	{
		Person** temp = new Person * [size-1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if ((arr[i]->get_id()) != id)
			{
				temp[j]= arr[i];
				j++;
			}
		}
		delete[]arr;
		this->size--;
		arr = new Person * [size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[]temp;
		cout << "Deleted successfully" << endl;
	}
	else
	{
		cout << "This id does not find" << endl;
	}
}
