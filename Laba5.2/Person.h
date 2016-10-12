#include <stdio.h>

class Person	//любой человек
{
protected:
	char	fio[100];		    // ФИО
	char	date_of_birth[12];	// дата рождения
	char	pol[5];			    // пол
	Person * next;			    // указатель на следующего в списке
public:
	Person() { next = NULL; };
	// добавить следующего в список
	void SetPersonInfo(char*, char*, char*);	
	// функция вывода информации переопределяется в производных классах
	virtual void PersonInfo(void);
	// gjkexbnm 
	Person * GetNext() const;
	void SetNext(Person *);

	Person& operator=(const Person&);
};

// сотрудник
class Employee : public Person
{
	char job[50];               // должность сотрудника 
public:		
	Employee() { next = NULL; };
	Employee(char*);

	char* GetJob();
	void SetJob(char*);

	void PersonInfo() override;
};

class Manager : public Employee
{
	char department[50];
	Person * employers;	
public:
	Manager() { employers = nullptr; };
	Manager(char*);

	Person* GetLast() const;
	void AddEmployee(Person*);
	void PersonInfo() override;
};

class Chief : public Employee
{
	char firma[50];
	Person * managers;
public:
	Chief() { managers = nullptr; }
	Chief(char*);

	Person* GetLast() const;
	void AddManager(Person*);
	void PersonInfo() override;
};
