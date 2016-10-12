/*
������������ ������ �2
������� 11
�������� ���� ����������

program.cpp
*/

#include <iostream>
#include "conio.h"  // ��� ������ _getch()

using namespace std;

/* ��������� Pair */
struct Pair
{
	char * name;        // ���
	int value;          // ��������
};

// ����� Pairs
class Pairs
{
	Pair * prs;	        // ������ ���
	int length;         // ������ �������
	int count;		    // ���������� ��� � �������

public:
	void Init(const int _length);
	int GetValue(const char* _name, int &_value);
	void SetValue(char* _name, int _value);
	friend void Print(Pairs* _p);
};

void Pairs::Init(const int _length)
{
	length = _length;
	prs = new Pair[_length];
	count = 0;
}

int Pairs::GetValue(const char* _name, int &_value)
{
	bool _found = false;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(prs[i].name, _name) == 0) // ����� ������� ����
		{
			_value = prs[i].value;
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

void Pairs::SetValue(char* _name, int _value)
{
	bool _found = false;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(prs[i].name, _name) == 0) // ����� ������� ����
		{
			// ��������� ����� ��������
			prs[i].value = _value;
			_found = true;
			break;
		}
	}

	if (!_found)
	{
		// ������� ����� ���� � ������		
		if (count == length) 
		{
			Pair * tmp_prs = new Pair[++length];
			for (int i = 0; i < length; i++)
			{
				tmp_prs[i].name = prs[i].name;
				tmp_prs[i].value = prs[i].value;
			}
			prs = tmp_prs;
			//delete[] tmp_prs;
		}
		// �������� ������� ������� ���
		count++;
		// ��������� �������� ��� ������ ��������
		prs[count - 1].name  = _name;
		prs[count - 1].value = _value;		
	}
}

// ���������� ������������� �������
void Print(Pairs *_p)
{
	cout << "------ Array of Pair 'name = value' ------" << endl;
	for (int i = 0; i < _p->length; i++)
	{
		cout << _p->prs[i].name << " = " << _p->prs[i].value << endl;
	}
	cout << "------------------------------------------" << endl;
}

int main()
{
	// ������� ������ ���
	Pairs _p;

	// �������������
	_p.Init(3);

	// ������� ����
	_p.SetValue("John", 5000);
	_p.SetValue("Sarah", 2500);
	_p.SetValue("Nick", 4000);
	
	// ����� �� �����
	Print(&_p);

	cout << "***** GetValue() *****" << endl;
	// ����� GetValue ��� ���������� �����
	int _val = 0;
	char _name[15];

	cout << "Enter name of Pair: ";
	cin >> _name;

	if (_p.GetValue(_name, _val) == 1)
	{
		cout << "Value for " << _name << " = " << _val << endl;
	}
	else
	{
		cout << "Pair with name <" << _name << "> not found!" << endl;
	}
	cout << "------------------------------------------" << endl;
	
	// ��������� ��������
	cout << "***** SetValue() *****" << endl;
	// ����� SetValue
	cout << "Enter name of Pair: ";
	cin >> _name;
	cout << "Enter new value for Pair: ";
	cin >> _val;
	_p.SetValue(_name, _val);
	cout << "------------------------------------------" << endl;
	
	Print(&_p);

	// �������� ����� ���� �� ��������� ����
	_getch();

	return 0;
}