#include "Department.h"
#include<time.h>
using namespace std;
void main()
{
	srand(time(0));
	
	Department* departments = new Department[5];
		
	for (int i = 0; i < 5; i++)
	{
		departments[i].CreateDepartment();
		/*cout << "Department number # ";
		cout << i+1 << endl;
		departments[i].PrintDepartment();*/
	}
	int num;
	cout << "Enter number of department";
	cin >> num;
	departments[num].PrintDepartment();
	int dismiss;
	cout << "Enter PersonalNumber of worker" << endl;
	cin >> dismiss;	
	departments->DeleteWorker(dismiss);

}