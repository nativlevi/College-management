#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Data.h"
Data::Data()
{//áðàé ãéôåìèéáé
	arr = NULL;
	size = 0;
}
Data::~Data()
{//ôåð÷öéä äåøñú 
	for (int i = 0; i < size; i++)
	{
		delete arr[i];//îçé÷ú îöáéò ðåëçé
	}
	delete[] arr;//îçé÷ú äîöáéò ìîòøê äàåáéé÷èéí
}
void Data::operator+=(Person* p)
{//äåñôú àãí ìîàâø
	if (size == 0)
	{//áîéãä åäîàâø øé÷
		arr = new Person * [1];//ä÷öàú î÷åí àçã
		arr[size] = p;//äåñôú äàãí ù÷éáìðå
		size++;
		return;//ñéåí äôåð÷öéä
	}
	Person** temp = new Person * [size];//äâãøú îòøê áâåãì ùéù ìðå ìùîéøú äòøëéí
	int i;//àéðã÷ñ
	for (i = 0; i < size; i++)
	{
		temp[i] = arr[i];//äòú÷ú äàðùéí ù÷ééîéí ëáø áîàâø
	}
	delete[]arr;//îçé÷ú äîöáéò ìîòøê ùì äîàâø
	arr = new Person * [size + 1];//ä÷öàä áâåãì äîãåéé÷ äçãù
	for (i = 0; i < size; i++)
	{
		arr[i] = temp[i];//äçæøú äòøëéí ùùîøðå átemp 
	}
	arr[size] = p;//äåñôú äàåáéé÷è ù÷éáìðå
	delete[]temp;//îçé÷ú îöáéò òæø
	size++;//òãëåï äâåãì äçãù
	return;//ñéåí äôåð÷öéä
}
void Data::print_all()const
{//äãôñú äîàâø
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i]->print();//æéîåï ôåð÷öéåú ääãôñä áäúàí ìñåâ äàåáéé÷è
		if (dynamic_cast <Employee*>(arr[i]))
		{
			cout << "Salary: " << dynamic_cast <Employee*>(arr[i])->salary() << endl;//äãôñú îùëåøú
		}
		cout << "~~~~~~~~~~~~~~~~~~" << endl;
	}
}
bool Data::find(int long id)
{//çéôåù àåáéé÷è áîàâø ä÷ééí
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->get_id() == id)//àí äúòåãú æäåú ù÷éáìðå æää ìúòåãú æäåú ùì äàåáéé÷è
			return true;//îöàðå àåáéé÷è æää
	}
	return false;//àéï àãí ëæä áîàâø
}
void Data::init()
{
	int days;
	int choise; //áçéøú ñåâ îúàéí îäúôøéè
	char name[20]; //îòøê ñèèé ì÷ìéèú ùí
	long id; //úòåãú æäåú
	int seniority;//ðéñéåï
	float average = 0.0; //îîåöò
	long phone_num;//îñôø èìôåï ùì îæëéøä
	int extra_hours;//ùòåú ðåñôåú ùì àá áéú
	int num_of_courses;//îñôø ÷åøñéí ùì îøöä
	int weekly_hours;//ùòåú ùáåòéåú ùì îúøâì
	char name_of_teza[30];//ùí èæä
	Person* p;//îöáéò òæø
	int work_hours;//ùòåú òáåãä ùì äîð÷ä
	char nameofdepartment[30];//îçì÷ä


	cout << "Please enter:" << endl;//äãôñú úôøéè
	cout << "1-Student" << endl;
	cout << "2-Employee" << endl;
	cout << "3-Working Student" << endl;
	cout << "0-EXIT" << endl;

	cin >> choise;
	int choise2;//îùúðä ìùîéøú äáçéøú äùðééä

	while (choise)//ëì òåã ìà ð÷ìè 0
	{
		switch (choise)//áçéøú äèéôåñ äîúàéí
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
				{//áãé÷ä ùúòåãú äæäåú ìà çåæøú òì òöîä 
					cout << "ID exist, try again " << endl;
					cin >> id;
				}
				cout << "Average: ";
				cin >> average;
				while (average < 0 || average>100)
				{//ú÷éðåú îîåöò
					cout << "Average must be between 0-100. Please enter new average:" << endl;
					cin >> average;
				}
				cout << endl;
				if (average <= 65)
				{
					cout << "You are entitled to a practitioner. Contact the college secretary.";
					cout << endl;
				}
				cout << "Number Of Courses: ";
				cin >> num_of_courses;
				while (num_of_courses < 0)
				{//ú÷éðåú îñôø ÷åøñéí
					cout << "Number of courses must be positive. Please enter new number of courses: " << endl;
					cin >> num_of_courses;
				}
				cout << endl;
				cout << "Name Of Department: ";
				cin >> nameofdepartment;
				cout << "please enter How many days are missing in the year?";
				cin >> days;
				cout << endl;
				p = new BA(name, id, average, num_of_courses,days, nameofdepartment);
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
				{//ú÷éðåú îîåöò
					cout << "Average must be between 0-100. Please enter new average:" << endl;
					cin >> average;
				}
				cout << endl;
				if (average <= 65)
				{
					cout << "You are entitled to a practitioner. Contact the college secretary.";
					cout << endl;
				}
				cout << "Number of courses: ";
				cin >> num_of_courses;
				while (num_of_courses < 0)
				{//ú÷éðåú îñôø ÷åøñéí
					cout << "Number of courses must be positive. Please enter new number of courses: " << endl;
					cin >> num_of_courses;
				}
				cout << endl;
				cout << "Name of teza: ";
				cin >> name_of_teza;
				cout << endl;
				cout << "please enter How many days are missing in the year?";
				cin >> days;
				cout << endl;
				p = new MA(name, id, average, num_of_courses,days, name_of_teza);
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
				{//ú÷éðåú îñôø ÷åøñéí
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
			{//áãé÷ä ùúòåãú äæäåú ìà çåæøú òì òöîä 
				cout << "ID exist, try again " << endl;
				cin >> id;
			}
			cout << "Average: " << endl;
			cin >> average;
			while (average < 0 || average>100)
			{//ú÷éðåú îîåöò
				cout << "Average must be between 0-100. Please enter new average: " << endl;
				cin >> average;
			}
			cout << endl;
			cout << "Number of courses: " << endl;
			cin >> num_of_courses;
			while (num_of_courses < 0)
			{//ú÷éðåú îñôø ÷åøñéí
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
			p = new WorkingStudent(name, id, average, num_of_courses, days, name_of_teza, seniority, weekly_hours);
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
		cin >> choise;//÷ìéèä îçãù
	}
	return;
}
bool Data::search(long id)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]->get_id() == id)
		{
			cout << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << "This id was found on the list. Details of person:" << endl;
			arr[i]->print();
			cout << "~~~~~~~~~~~~~~~~~~" << endl;
			return true;
		}
	}
	return false;
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
