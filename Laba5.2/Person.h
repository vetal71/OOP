#include <stdio.h>

class Person	//����� �������
{
protected:
	char	fio[100];		    // ���
	char	date_of_birth[12];	// ���� ��������
	char	pol[5];			    // ���
	Person * next;			    // ��������� �� ���������� � ������
public:
	Person() { next = NULL; };
	// �������� ���������� � ������
	void SetPersonInfo(char*, char*, char*);	
	// ������� ������ ���������� ���������������� � ����������� �������
	virtual void PersonInfo(void);
	// gjkexbnm 
	Person * GetNext() const;
	void SetNext(Person *);

	Person& operator=(const Person&);
};

// ���������
class Employee : public Person
{
	char job[50];               // ��������� ���������� 
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
