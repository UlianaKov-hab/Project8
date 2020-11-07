#include "Department.h"

void Department::CreateDepartment()
{
	CountWorker = 1 + rand() % 5;
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

void Department::AddWorker()
{
	Worker* workers1 = new Worker[CountWorker+1];
	for (int i = 0; i < CountWorker; i++)
	{
		workers1[i]=workers[i];
	}
	workers1[CountWorker].CreateWorker();
	delete[] workers;
	CountWorker++;
	workers = workers1;
}

void Department::DeleteWorker(int dismiss)
{
	Worker* workers1 = new Worker[CountWorker - 1];
	for (int i = 0; i < CountWorker; i++)
	{
		if (dismiss != workers->PersonalNumber)
		{
			workers1[i] = workers[i];
		}
		else
		{
			workers1[i] = workers[i+1];
		}
		
	}
	delete[] workers;
	CountWorker--;
}


