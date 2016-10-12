#include <conio.h>
#include "Person.h"

int main(int argc, char* argv[])
{
	Chief * chief = new Chief("Roga i kopyta");
	chief->SetPersonInfo("Ostap Bender", "12.12.1212", "M");
	chief->SetJob("Chief");

	Manager * m1 = new Manager("Roga");
	m1->SetPersonInfo("Shura", "01.01.0101", "M");
	m1->SetJob("Manager");
	
	Manager * m2 = new Manager("Kopyta");
	m2->SetPersonInfo("Ponikovski", "10.10.1010", "M");
	m2->SetJob("Manager");
	
	chief->AddManager(m1);
	chief->AddManager(m2);
	
	Employee * emp1 = new Employee("Worker");
	emp1->SetPersonInfo("Ivan Ivanov", "02.02.2002", "M");
	m1->AddEmployee(emp1);

	Employee * emp2 = new Employee("Secretary");
	emp2->SetPersonInfo("Sarah Conor", "15.12.1970", "W");
	m1->AddEmployee(emp2);

	Employee * emp3 = new Employee("Security");
	emp3->SetPersonInfo("Arnold Shwarcneger", "12.06.1950", "M");
	m1->AddEmployee(emp3);

	Employee * emp4 = new Employee("Economist");
	emp4->SetPersonInfo("Abram Abramovich", "02.02.2002", "M");
	m2->AddEmployee(emp4);

	Employee * emp5 = new Employee("Buhgalter");
	emp5->SetPersonInfo("Sonya Croycman", "15.12.1985", "W");
	m2->AddEmployee(emp5);

	Employee * emp6 = new Employee("Worker");
	emp6->SetPersonInfo("Jastin Biber", "12.06.1990", "M");
	m2->AddEmployee(emp6);

	chief->PersonInfo();

	_getch();

	return 0;
}