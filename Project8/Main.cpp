#include "Department.h"
#include<time.h>
using namespace std;

void main()
{
	//srand(time(0));
	int NumberDepartment = 1 + rand() % 5;
	Department* departments= new Department[NumberDepartment];
		
		for (int i = 0; i < 5; i++)
		{
			departments[i].CreateDepartment();
			cout << "Department number # ";
			cout << NumberDepartment << endl;
			departments[i].PrintDepartment();
		}
}