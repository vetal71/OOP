/*
������������ ������ �4
������� 11
�������� ���� ����������

program.cpp
*/

#include <iostream>
#include <string.h>
#include "conio.h"  // ��� ������ _getch()

using namespace std;

/* ��������� Pair */
struct Pair
{
	char * name;        // ���
	int value;          // ��������

	Pair& operator=(int);                                  // ���������� ��������
	Pair& operator=(const char *);                         // ���������� ���
	friend istream& operator>>(istream& is, Pair&);        // ����
	friend ostream& operator<<(ostream& os, const Pair&);  // �����
};

// ����� Pairs
class Pairs
{
	Pair * prs;	        // ������ ���
	int length;         // ������ �������
	int count;		    // ���������� ��� � �������

public:
	Pairs() { length = 0; count = 0; prs = nullptr; };

	Pairs& operator=(const Pairs&);                        // ����������� ���
	Pairs& operator+=(const Pairs&);                       // ���������� ���
	Pairs& operator+=(const Pair&);                        // ���������� ����� ����
	char * operator[](int);                                // ��������� ����� �� ��������
	int operator[](const char *);                          // ��������� �������� �� �����
	friend ostream& operator<<(ostream& os, const Pairs&); // �����
};

Pair& Pair::operator=(int _value)
{
	value = _value;
	return *this;
}


Pair& Pair::operator=(const char* _name)
{
	strcpy_s(name, sizeof(_name), _name); 
	return *this;
}

istream& operator>>(istream& is, Pair& _p)
{
	char _name[15] = "";
	int _value;
	cout << "Enter new name: ";
	is.getline(_name, 15);	
	cout << "Enter new value:";
	is >> _value;	

	_p.name  = _name;
	_p.value = _value;
	
	return is;
}

ostream& operator<<(ostream& os, const Pair& _p)
{
	char * _name = "";
	_name = _p.name;
	os << _p.name << " = " << _p.value << endl;
	return os;
}

// ����������� ���
Pairs& Pairs::operator=(const Pairs& _p)
{
	// �������� �� ����������� ������ ����
	if (this != &_p)
	{
		prs = new Pair[length = _p.length];
		// ����������� ���
		for (int i = 0; i < length; i++)
		{
			prs[i] = _p.prs[i];
		}
		count = _p.count;
	}
	return *this;
}

// ���������� ���
Pairs& Pairs::operator+=(const Pairs& _p)
{
	prs = new Pair[length += _p.length];
	// ����������� ���
	for (int i = 0; i < length; i++)
	{
		prs[i] = _p.prs[i];
	}
	count += _p.count;
	return *this;
}

// ���������� ����
Pairs& Pairs::operator+=(const Pair& _p)
{
	prs = new Pair[length + 1];
	count++;
	prs[count - 1] = _p.name;
	prs[count - 1] = _p.value;
	return *this;
}

// ��������� ����� �� ��������
char* Pairs::operator[](int _value)
{	
	char * res = "not found";
	for (int i = 0; i < count; i++)
	{
		if (prs[i].value == _value) // ����� ������� ����
		{
			strcpy_s(res, sizeof(prs[i].name), prs[i].name);
			break;
		}
	}
	return res;
}

// ��������� �������� �� �����
int Pairs::operator[](const char* _name)
{
	int res = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(prs[i].name, _name) == 0) // ����� ������� ����
		{
			res = prs[i].value;
			break;
		}
	}
	return res;
}

// �����
ostream& operator<<(ostream& os, const Pairs& _p)
{
	os << "------ Array of Pair 'name = value' ------" << endl;
	for (int i = 0; i < _p.length; i++)
	{
		os << _p.prs[i];
	}
	os << "------------------------------------------" << endl;
	return os;
}

int main()
{
	Pair pair;
	Pairs pairs;

	// �������� ����� ��� ����
	pair.name = "A";
	pair.value = 1;
	
	cin >> pair;

	cout << pair;

	// ���������� ����
	//pairs += pair;

	//cout << pairs;
	
	// �������� ����� ���� �� ��������� ����
	_getch();

	return 0;
}
