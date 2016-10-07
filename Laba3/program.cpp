/*
������������ ������ �3
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
	// ����������� �� ���������
	Pairs();
	// ����������� � �����������
	Pairs(const int _length);
	// ����������� �����������
	Pairs(const Pairs &_prs);
	// ����������
	~Pairs();

	void Init(const int _length);
	int GetValue(const char* _name, int &_value) const;
	void SetValue(char* _name, int _value);
	friend void Print(Pairs* _p);
};


Pairs::Pairs()
{
	cout << "Default constructor Pairs()" << endl;
	length = 0;
	count  = 0;
	prs = nullptr;
}

Pairs::Pairs(const int _length)
{
	cout << "Constructor with parameters" << endl;
	length = _length;
	prs = new Pair[_length];
	count = 0;
}

Pairs::Pairs(const Pairs& _p)
{
	cout << "Constructor for copy object" << endl;	
	prs = new Pair[length = _p.length];
	// ����������� ���
	for (int i = 0; i < length; i++)
	{
		prs[i] = _p.prs[i];
	}
	count = _p.count;
}

Pairs::~Pairs()
{
	cout << "Destructor ~Pairs()" << endl;
	delete[] prs;
}

void Pairs::Init(const int _length)
{
	length = _length;
	prs = new Pair[_length];
	count = 0;
}

int Pairs::GetValue(const char* _name, int &_value) const
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
			delete[] tmp_prs;
		}
		// �������� ������� ������� ���
		count++;
		// ��������� �������� ��� ������ ��������
		prs[count - 1].name = _name;
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
	// ����������� �� ���������
	Pairs p1;
	p1.Init(3);
	// ������� ����
	p1.SetValue("John", 5000);
	p1.SetValue("Sarah", 2500);
	p1.SetValue("Nick", 4000);
	Print(&p1);
	
	// ����������� � �����������
	Pairs p2(3);
	p2.SetValue("Ann", 3000);
	p2.SetValue("Frank", 6500);
	p2.SetValue("Bill", 4900);
	Print(&p2);

	// ����������� �����������
	Pairs p3 = p2;
	Print(&p3);

	cout << "***** GetValue() *****" << endl;
	// ����� GetValue ��� ���������� �����
	int _val = 0;
	char _name[15];

	cout << "Enter name of Pair: ";
	cin >> _name;

	if (p3.GetValue(_name, _val) == 1)
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
	p3.SetValue(_name, _val);
	cout << "------------------------------------------" << endl;

	Print(&p3);
	
	// �������� ����� ���� �� ��������� ����
	_getch();

	return 0;
}