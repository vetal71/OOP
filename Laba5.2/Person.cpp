#include "Person.h"
#include <iostream>

using namespace std;

void Person::SetPersonInfo(char* _fio, char* _birthday, char* _pol)
{
	strcpy_s(fio, sizeof fio, _fio);
	strcpy_s(date_of_birth, sizeof date_of_birth, _birthday);
	strcpy_s(pol, sizeof pol, _pol);
	next = nullptr;
}

void Person::PersonInfo()
{
	// вывод на экран
	cout << "FIO            : " << fio << endl;
	cout << "Date of Birtday: " << date_of_birth << endl;
	cout << "Sex            : " << pol << endl;
} 

Person* Person::GetNext() const
{
	return next;
}

void Person::SetNext(Person* _p)
{
	next = _p;
}

Person& Person::operator=(const Person& _p)
{
	if (&_p != nullptr) 
	{
		strcpy_s(fio, sizeof fio, _p.fio);
		strcpy_s(date_of_birth, sizeof date_of_birth, _p.date_of_birth);
		strcpy_s(pol, sizeof pol, _p.pol);
		next = _p.next;
		return *this;
	} 	
}

Employee::Employee(char* _job)
{
	strcpy_s(job, sizeof job, _job);
}

char* Employee::GetJob()
{
	return job;
}

void Employee::SetJob(char* _job)
{
	strcpy_s(job, sizeof job, _job);
}

void Employee::PersonInfo()
{
	Person::PersonInfo();
	cout << "Job            : " << job << endl;
}

Manager::Manager(char* _dep)
{
	strcpy_s(department, sizeof department, _dep);
	employers = nullptr;
}

void Manager::AddEmployee(Person* _p)
{
	// Добавление элемента
	if (employers == nullptr)
	{
		employers = _p;		
	}
	else
	{
		Person * last = employers;		
		while (last->GetNext())
		{
			last = last->GetNext();
		}		
		last->SetNext(_p);		
	}		
}

void Manager::PersonInfo()
{
	Employee::PersonInfo();
	cout << "Department     : " << department << endl;
	cout << "--- Employers ------------------------------" << endl;
	
	Person * current;
	current = employers;
	while (current)
	{
		current->PersonInfo();
		current = current->GetNext();
		cout << "--------------------------------------------" << endl;
	}
}

Chief::Chief(char* _firma)
{
	strcpy_s(firma, sizeof firma, _firma);
	managers = nullptr;
}

Person* Chief::GetLast() const
{
	Person * current;
	current = managers;
	while (current)
	{
		current = current->GetNext();
	}
	return current;
}

void Chief::AddManager(Person* _m)
{	
	// Добавление элемента
	if (managers == nullptr)
	{
		managers = _m;
	}
	else
	{
		Person * last = managers;
		while (last->GetNext())
		{
			last = last->GetNext();
		}
		last->SetNext(_m);
	}
}

void Chief::PersonInfo()
{
	cout << "------------" << firma << "------------------" << endl;
	Employee::PersonInfo();		
	Person * current;
	current = managers;
	while (current)
	{
		cout << "---- Managers ------------------------------" << endl;
		current->PersonInfo();
		current = current->GetNext();		
	}
}

