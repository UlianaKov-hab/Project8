#include "Worker.h"

void Worker::CreateWorker()
{
	string fn [10] = { "Ivan", "Oleg", "Maksim", "Oleksandr", "Misha", "Tanya", "Vera", "Olga", "Iryna", "Sveta" };
	string ln [10] = { "Skidan", "Kovalchuk", "Ivanov", "Petrov", "Sidorov", "Boyko", "Vitruk", "Oleniuk", "Lozinsky", "Maksimchuk" };
	string pos[7] = { "Engeneer", "Accountant", "Depertment head", "Driver", "Secretary", "Cleaner", "Personnel officer" };
	int a, b, c;
	a = rand() % 10;
	b = rand() % 10;
	c = rand() % 7;
	FirstName = fn[a];
	LastName = ln[b];
	Position = pos[c];
	PersonalNumber = 4789 + rand() % 5639;
	for (int j=0; j < 12; j++)
	{
		NumberHoursWorked[j] = 100 + rand() % 164;
		NumberDaysWorked[j] = 1+rand() % 22;
	}
	
}

void Worker::PrintWorker()
{
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Position: " << Position << endl;
	cout << "Personal number: " << PersonalNumber << endl;
	cout << "Hours worked per month: ";
	for (int i=0; i < 12; i++)
	{
		cout << NumberHoursWorked[i] << " ";
	}
	cout << endl;
	cout << "Worked days in a month: ";
	for (int i=0; i < 12; i++)
	{
		cout << NumberDaysWorked[i] << " ";
	}
	cout << endl;

}
