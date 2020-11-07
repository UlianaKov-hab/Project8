#include "Department.h"
using namespace std;
void main()
{
	srand(time(0));
	Department departments[4];
	int NumberDepartment[4]{ 1, 2, 3, 4 };
	//NumberDepartment = 1 + rand() % 4;
	for (int i = 0; i < 3; i++)
	{
		departments[i].CreateDepartment(NumberDepartment[i])

	}
	



}