#include "Department.h"

#include<time.h>
using namespace std;

void main()
{
	//srand(time(0));
	int size = 5;
	Department* departments = new Department[size];

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
}