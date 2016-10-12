/*
Eaai?aoi?iay ?aaioa ?4
Aa?eaio 11
Eieaniee Eeuy Aeoaeuaae?
program.cpp
*/

#include <iostream>
#include <string.h>
#include "conio.h"  // aey auciaa _getch()

using namespace std;

/* No?oeoo?a Pair */
struct Pair
{
	char * name;        // eiy
	int value;          // cia?aiea

	Pair& operator=(int);                                  // onoaiiaeou cia?aiea
	Pair& operator=(const char *);                         // onoaiiaeou eiy
	friend istream& operator>>(istream& is, Pair&);        // aaia
	friend ostream& operator<<(ostream& os, const Pair&);  // auaia
};

// Eeann Pairs
class Pairs
{
	Pair * prs;	        // iannea ia?
	int length;         // ?acia? ianneaa
	int count;		    // eiee?anoai ia? a ianneaa

public:
	Pairs() { length = 0; count = 0; prs = nullptr; };

	Pairs& operator=(const Pairs&);                        // eiie?iaaiea ia?
	Pairs& operator+=(const Pairs&);                       // aiaaaeaiea ia?
	Pairs& operator+=(const Pair&);                        // aiaaaeaiea iiaie ia?u
	char * operator[](const int);                          // iieo?aiea eiaie ii cia?aie?
	int operator[](const char *);                          // iieo?aiea cia?aiey ii eiaie
	friend ostream& operator<<(ostream& os, const Pairs&); // auaia
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
	// aniiiaaaoaeuiua ia?aiaiiua
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

// eiie?iaaiea ia?
Pairs& Pairs::operator=(const Pairs& _p)
{
	// i?iaa?ea ia eiie?iaaiea naiiai naay
	if (this != &_p)
	{
		prs = new Pair[length = _p.length];
		// eiie?iaaiea ia?
		for (int i = 0; i < length; i++)
		{
			prs[i] = _p.prs[i];
		}
		count = _p.count;
	}
	return *this;
}

// aiaaaeaiea ia?
Pairs& Pairs::operator+=(const Pairs& _p)
{	
	Pair * tmp_prs = new Pair[length + _p.length + 1];
	// eiie?iaaiea ia?
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

// aiaaaeaiea ia?u
Pairs& Pairs::operator+=(const Pair& _p)
{
	Pair * tmp_prs = new Pair[++length];
	if (count > 0) 
	{
		// eiie?iaaiea ia?
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

// iieo?aiea eiaie ii cia?aie?
char* Pairs::operator[](const int _value)
{	
	for (int i = 0; i < count; i++)
	{
		if (prs[i].value == _value) // iaoee eneiio? ia?o
		{
			return prs[i].name;
		}
	}
	return "not found";
}

// iieo?aiea cia?aiey ii eiaie
int Pairs::operator[](const char* _name)
{
	int res = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(prs[i].name, _name) == 0) // iaoee eneiio? ia?o
		{
			res = prs[i].value;
			break;
		}
	}
	return res;
}

// auaia
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

	// aiaaaeaiea ia?u
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

	// i?eaaiea aaiaa ?oiau ia cae?ueinu ieii
	_getch();

	return 0;
}