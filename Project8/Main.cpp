#include "Department.h"

#include<time.h>
using namespace std;

void main()
{
	//srand(time(0));
	Department* departments = new Department[5];

	for (int i = 0; i < 5; i++)
	{
		departments[i].CreateDepartment();
		//cout << "Department number # ";
		//cout << i+1 << endl;
		//departments[i].PrintDepartment();
	}
	
	while (MainMenu(departments) != 7)
	{

	}
	

	//srand(time(0));
	
	

	//////////////// AddWorker///////////
	/*int index;
	cout << "Enter number of department ";
	cin >> index;
	departments[index].PrintDepartment();
	cout << "____________________________________"<< endl;
	AddWorker(departments, index);
	departments[index].PrintDepartment();*/
	//////////////////////////////////



	///////////////////////////////// Delete worker
	/*int index;
	cout << "Enter number of department ";
	cin >> index;
	departments[index].PrintDepartment();
	cout << "____________________________________" << endl;
	int dismiss;
	cout << "Enter Personal number of worker ";
	cin >> dismiss;	
	DeleteWorker(departments,index, dismiss);
	departments[index].PrintDepartment();*/
	///////////////////////////////
	/*string FirstNameFind;
	string LastNameFind;
	int PersonalNumberFind;

	cout << "Enter information about the worker to search:"<<endl;
	cout << "First name: ";
	cin >> FirstNameFind;	
	cout << "Last name: ";
	cin >> LastNameFind;	
	cout << "Personal number: ";
	cin >> PersonalNumberFind;	*/
	
	//departments
	//departments->FindWorker();
	//departments[1].FindWorker(departments);
	//FindWorker( departments);
	////////////////////
	

}