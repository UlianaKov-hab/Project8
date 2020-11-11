#include "Department.h"
using namespace std;

void Department::CreateDepartment() //1
{
	CountWorker = 1 + rand() % 5;
	workers = new Worker[CountWorker];
	for (int i = 0; i < CountWorker; i++)
	{
		 workers[i].CreateWorker();
	}	
}

void Department::PrintDepartment() //2
{	
	for (int i = 0; i < CountWorker; i++)
	{
		workers[i].PrintWorker();
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}
void AddWorker(Department* departments, int index) //3
{
	Worker* workers1 = new Worker[departments[index].CountWorker+1];
	for (int i = 0; i < departments[index].CountWorker; i++)
	{
		workers1[i]= departments[index].workers[i];
	}
	workers1[departments[index].CountWorker].CreateWorker();
	delete[] departments[index].workers;
	departments[index].CountWorker++;
	departments[index].workers = workers1;
}

void SortWorkers(Department* departments) //5
{
	int count_workers = 0;
	for (int i = 0; i < 5; i++)
	{
		count_workers+=departments[i].CountWorker;				
	}
	cout << count_workers << endl;
	Worker* workers1 = new Worker[count_workers];
	for (int i = 0, k=0; i < 5; i++)
	{
		for (int j = 0; j < departments[i].CountWorker; j++, k++)
		{
			workers1[k] = departments[i].workers[j];
		}
	}
	for (int i = 0; i < count_workers; i++)
	{
		for (int j = 0; j < count_workers-1; j++)
		{
			if (workers1[j].LastName > workers1[j+1].LastName)
			{
				swap(workers1[j].LastName , workers1[j + 1].LastName);
			}
		}
	}
	for (int i = 0; i < count_workers; i++)
	{
		workers1[i].PrintWorker();
		cout << endl;
	}
	
	/*int j;
	Department temp;

	for (int i = 0; i < departments[index].CountWorker; i++)
	{
		j = i - 1;
		while (j >= 0 && strcmp(departments[index].workers[j + 1].FirstName[0], departments[index].workers[j].FirstName[0]) < 0)
		{
			temp = departments[index].workers[j + 1];
			departments[index].workers[j + 1] = departments[index].workers[j];
			j--;
		}
	}*/
}

void FindWorker(Department* departments) //6
{
	string FirstNameFind;
	string LastNameFind;
	int PersonalNumberFind;

	cout << "Enter information about the worker to search:" << endl;
	cout << "First name: ";
	cin >> FirstNameFind;
	cout << "Last name: ";
	cin >> LastNameFind;
	//cout << "Personal number: ";
	//cin >> PersonalNumberFind;
	cout << endl;
	system("CLS");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < departments[i].CountWorker; j++)
		{
			if (departments[i].workers[j].FirstName == FirstNameFind && departments[i].workers[j].LastName == LastNameFind)
			{
				departments[i].workers[j].PrintWorker();
			}
		}
	}	
}
void DepartmentData(Department* departments, int index) //7
{
	int count_worked_hours = 0;	
	int month;	
	cout << "Enter number of month  ";
	cin >> month;
	for (int i = 0; i < departments[index].CountWorker; i++)
	{				
		for (int m = 0; m < 12; m++)
		{					
			count_worked_hours += departments[index].workers[i].NumberHoursWorked[month - 1];
		}		
	}
	cout << "Department " << index+1 << endl;
	cout << "Number of hours worked in "<< month<<" months: " << count_worked_hours << endl;	
}

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

int Menu(string menu_items[], int SIZE)
{
	int key = 0;
	int code;
	do {
		//system("cls");
		key = (key + SIZE) % SIZE;
		for (int i = 0; i < SIZE; i++)
		{
			SetPos(0, 2 + i);
			if (key == i)
			{

				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}

		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;

	//return 0;
}

int MenuDep(Department* departments)
{
	int index;
	Size_Console(65, 45);
	string menu[] = { "Department # 1","Department # 2",
		"Department # 3","Department # 4",
		"Department # 5", "Exit" };
	int m = Menu(menu, size(menu));
	if (m == 0)
	{				
		index = 0;
		
	}
	if (m == 1)
	{
		index = 1;
	}
	if (m == 2)
	{
		index = 2;
	}
	if (m == 3)
	{
		index = 3;
	}
	if (m == 4)
	{
		index = 4;
	}	
	//system("pause");
	//system("CLS");
	return m;
}


int MainMenu(Department* departments)
{
	Size_Console(65, 45);
	string menu[] = { "1.Show all workers data","2.Add worker",
		"3.Delete worker","4.Sort workers by Last Name",
		"5.Find worker", "6.Show the number of hours worked by month in the department",
		"7.Groups with the most privileges", "8.Exit" };
	int m = Menu(menu, size(menu));
	if (m == 0) //Show all workers data
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Department number # ";
			cout << i+1 << endl;
			departments[i].PrintDepartment();
		}
	}
	if (m == 1)//Add worker
	{
		cout << "Select department"<<endl;		
		//MenuDep(departments);
		//system("pause");
		//system("CLS");
		int index = MenuDep(departments);
		departments[index].PrintDepartment();
		cout << "_________________" << endl;
		AddWorker(departments, index);
		departments[index].PrintDepartment();
	}
	if (m == 2) //DeletWorcer
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);
		departments[index].PrintDepartment();
		cout << "_________________" << endl;

		
	}
	if (m == 3) //Sort workers
	{
		
		SortWorkers(departments);
		
	}
	if (m == 4)
	{
		
		FindWorker(departments);
	}
	if (m == 5)
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);
		DepartmentData(departments, index);
	}
	if (m == 6)
	{
		

	}
	system("pause");
	system("CLS");
	return m;
}



//int menuWorker(Departament* departaments)
//{
//	int key = 0;
//	int code;
//	do {
//		system("cls");
//
//		key = (key + CountWorker) % CountWorker;
//
//		for (int i = 0; i < CountWorker; i++)
//		{
//			if (key == i)
//			{
//
//				SetColor(6);  workers[i].PrintWorker(); SetColor(3); SetColor(15);
//			}
//			else
//			{
//				workers[i].PrintWorker();
//			}
//
//		}
//		code = _getch();
//		if (code == 224)
//		{
//			code = _getch();
//			if (code == 80) key++;
//			if (code == 72) key--;
//		}
//	} while (code != 13);
//	system("cls");
//	return key;
//}
//int menuWorker(Worker* workers, int CountWorker)
//{
//	int key = 0;
//	int code;
//	do {
//		system("cls");
//
//		key = (key + CountWorker) % CountWorker;
//
//		for (int i = 0; i < CountWorker; i++)
//		{
//			if (key == i)
//			{
//
//				SetColor(6);  workers[i].PrintWorker(); SetColor(3); SetColor(15);
//			}
//			else
//			{
//				workers[i].PrintWorker();
//			}
//
//		}
//		code = _getch();
//		if (code == 224)
//		{
//			code = _getch();
//			if (code == 80) key++;
//			if (code == 72) key--;
//		}
//	} while (code != 13);
//	system("cls");
//	return key;
//}
//void DeleteWorker(Department* departments, int index, int dismiss) //4
//{
//
//	Worker* workers1 = new Worker[departments[index].CountWorker - 1];
//	for (int i = 0; i < departments[index].CountWorker; i++)
//	{
//		if (dismiss != departments[index].workers->PersonalNumber)
//		{
//			workers1[i] = departments[index].workers[i];
//		}
//		else
//		{
//			workers1[i] = departments[index].workers[i+1];
//		}
//		
//	}
//	delete[] departments[index].workers;
//	departments[index].CountWorker--;
//}
//

//
//
//	
//	
//}
//
//
//
//void Average_amount_no_worked_day_depart_per_year(Department* departments) //9
//{
//	int nembe_department;
//	float sum;
//	float average_amount_no_worked_day_depart[5];
//	for (int i = 0; i < 5; i++)
//	{
//		sum = 0;
//		for (int j = 0; j < departments[i].CountWorker; j++)
//		{
//			for (int m = 0; m < 12; m++)
//			{
//				sum+= departments[i].workers[j].NumberDaysNoWorked[m];
//			}
//		}
//		average_amount_no_worked_day_depart[i] = sum/ departments[i].CountWorker/12;
//	}
//	cout << "Enter number of department: ";
//	cin >> nembe_department;
//	cout << "Average amount no worked day in department " << nembe_department << " per year: " << average_amount_no_worked_day_depart[nembe_department - 1];
//}
//
//void Count_no_worked_day_by_month(Department* departments) //10
//{
//	int no_worked_day_by_month[5][12];
//	int sum;
//	for (int i = 0; i < 5; i++)
//	{		
//		sum = 0;
//		for (int m = 0; m < 12; m++)
//		{
//			sum;
//			for (int j = 0; j < departments[i].CountWorker; j++)
//			{
//				sum+= departments[i].workers[j].NumberDaysNoWorked[m];
//			}
//			no_worked_day_by_month[i][m] = sum;
//		}			
//	}
//	cout << "Number no worked days per mohths";
//	
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Depaptment "<<i+1 << endl;
//		for (int m = 0; m < 12; m++)
//		{
//			cout<<setw(2)<<no_worked_day_by_month[i][m];
//		}
//		cout << endl;
//	}
//}
//
//void Count_no_worked_day_per_year(Department* departments)
//{
//	int count_no_worked_day_per_year=0;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < departments[i].CountWorker; j++)
//		{
//			for (int m = 0; m < 12; m++)
//			{
//				count_no_worked_day_per_year+= departments[i].workers[j].NumberDaysNoWorked[m];
//			}
//		}
//	}
//	cout << "Total days not worked per year: " << count_no_worked_day_per_year << endl;
//
//}


//for (int i = 0; i < 5; i++)
//{
//	for (int j = 0; j < CountWorker; j++)
//	{
//		for (int m = 0; m < 12; m++)
//		{
//
//		}
//	}
//}