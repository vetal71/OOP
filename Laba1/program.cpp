/*
	������������ ������ �1
	������� 11
	�������� ���� ����������

	program.cpp
*/

#include <iostream>
#include "conio.h"

using namespace std;

/* ��������� Pair */
struct Pair
{
	char * name;        // ���
	int value;          // ��������
};

// ���������
#define MAX_PAIRS 100   // ������������ ���������� ���

// ��������� Pairs
struct Pairs
{
	Pair p[MAX_PAIRS];	//������ ���
	int count;		    //���������� ��� � �������
};

int GetValue(const Pairs* _p, const char* _name, int &_value)
{	
	bool _found = false;
	for (int i = 0; i < _p->count; i++)
	{
		if (strcmp(_p->p[i].name, _name) == 0) // ����� ������� ����
		{
			_value = _p->p[i].value;
			_found = true;
			break;
		} 		
	}
	if (_found) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void SetValue(Pairs* _p, char* _name, int _value)
{
	bool _found = false;
	for (int i = 0; i < _p->count; i++)
	{		
		if (strcmp(_p->p[i].name, _name) == 0) // ����� ������� ����
		{
			// ��������� ����� ��������
			_p->p[i].value = _value;
			_found = true;
			break;
		}
	}

	if (!_found) 
	{
		// ������� ����� ���� � ������		
		_p->p[_p->count].name  = _name;
		_p->p[_p->count].value = _value;
		_p->count++;
	}
}

void PrintPairs(Pairs* _p)
{
	cout << "------ Array of Pair 'name = value' ------" << endl;
	for (int i = 0; i < _p->count; i++)
	{		
		cout << _p->p[i].name << " = " << _p->p[i].value << endl;
	}
	cout << "------------------------------------------" << endl;
}

int main()
{
	// ������� ������ ���
	Pairs _p;
	_p.count = 3;
	_p.p[0].name  = "John";
	_p.p[0].value = 5000;

	_p.p[1].name = "Sarah";
	_p.p[1].value = 2500;

	_p.p[2].name = "Nick";
	_p.p[2].value = 4000;

	// ����� �� �����
	PrintPairs(&_p);

	cout << "***** GetValue() *****" << endl;
	// ����� GetValue ��� ���������� �����
	int _val = 0;
	char _name[15];

	cout << "Enter name of Pair: ";
	cin >> _name;

	if (GetValue(&_p, _name, _val) == 1) 
	{
		cout << "Value for " << _name << " = " << _val << endl;
	}
	else
	{
		cout << "Pair with name <" << _name << "> not found!" << endl;
	}
	cout << "------------------------------------------" << endl;
	cout << "***** SetValue() *****" << endl;
	// ����� SetValue
	cout << "Enter name of Pair: ";
	cin >> _name;
	cout << "Enter new value for Pair: ";
	cin >> _val;

	SetValue(&_p, _name, _val);
	cout << "------------------------------------------" << endl;
	PrintPairs(&_p);

	// �������� ����� ���� �� ��������� ����
	_getch();
	
	return 0;
}