#include "Department.h"

void Department::CreateDepartment()
{
	CountWorker = 3 + rand() % 7;
	workers = new Worker[CountWorker];
	for (int i = 0; i < CountWorker; i++)
	{
		 workers[i].CreateWorker();
	}
	
}

void Department::PrintDepartment()
{
	for (int i = 0; i < CountWorker; i++)
	{
		workers[i].PrintWorker();
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}
