/*
������������ ������ �4
������� 11
�������� ���� ����������

program.cpp
*/

#define _CRT_SECURE_NOT_WARNING

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
	char * operator[](const int);                          // ��������� ����� �� ��������
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
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	
	return *this;
}

istream& operator>>(istream& is, Pair& _p)
{
	// ��������������� ����������
	is.clear();
	char * _name = new char[15];
	int _value;
	cout << "Enter new name: ";
	is >> _name;	
	cout << "Enter new value:";
	is >> _value;	

	_p.name  = _name;
	_p.value = _value;
	
	return is;
}

ostream& operator<<(ostream& os, const Pair& _p)
{
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
	Pair * tmp_prs = new Pair[length + _p.length + 1];
	// ����������� ���
	for (int i = 0; i < length; i++)
	{
		tmp_prs[i] = prs[i];
	}
	for (int i = 0; i < _p.length; i++)
	{
		tmp_prs[length + i] = _p.prs[i];
	}
	prs = tmp_prs;
	delete[] tmp_prs;
	count += _p.count;
	return *this;
}

// ���������� ����
Pairs& Pairs::operator+=(const Pair& _p)
{
	Pair * tmp_prs = new Pair[++length];
	if (count > 0) 
	{
		// ����������� ���
		for (int i = 0; i < length; i++)
		{
			tmp_prs[i] = prs[i];
		}
	}
	tmp_prs[length - 1] = _p;
	prs = tmp_prs;
	count++;
	return *this;
}

// ��������� ����� �� ��������
char* Pairs::operator[](const int _value)
{	
	for (int i = 0; i < count; i++)
	{
		if (prs[i].value == _value) // ����� ������� ����
		{
			return prs[i].name;
		}
	}
	return "not found";
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

	cout << "Overload operator >> for Pair" << endl;
	cin >> pair;

	cout << "Overload operator << for Pair" << endl;
	cout << pair;

	// ���������� ����
	cout << "Overload operator += for Pairs (append Pair)" << endl;
	pairs += pair;

	cout << "Overload operator << for Pairs" << endl;
	cout << pairs;
	
	Pairs pairs1;
	cout << "Overload operator += for Pairs (append Pairs)" << endl;
	pairs1 += pairs;
	cout << pairs1;

	Pairs pairs2;
	cout << "Overload operator = for Pairs (copy Pairs)" << endl;
	pairs2 = pairs;
	cout << pairs2;

	Pair pair1, pair2;
	cout << "Overload operator = for Pair" << endl;
	pair1 = "Jack";
	pair1 = 3000;
	pairs2 += pair1;
	cout << pairs2;
	
	cin >> pair2;
	pairs2 += pair2;
	
	int _value;
	cout << "Enter value for search: ";
	cin >> _value;	
	cout << "Found name: " << pairs2[_value] << endl;

	char * _name = new char[15];	
	cout << "Enter name for search: ";
	cin >> _name;
	_value = pairs2[_name];
	cout << "Found value: " << _value << endl;

	// �������� ����� ����� �� ��������� ����
	_getch();

	return 0;
}
