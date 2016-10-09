/*
Лабораторная работа №4
Вариант 11
Колесник Илья Витальевич

program.cpp
*/

#define _CRT_SECURE_NOT_WARNING

#include <iostream>
#include <string.h>
#include "conio.h"  // для вызова _getch()

using namespace std;

/* Структура Pair */
struct Pair
{
	char * name;        // имя
	int value;          // значение

	Pair& operator=(int);                                  // установить значение
	Pair& operator=(const char *);                         // установить имя
	friend istream& operator>>(istream& is, Pair&);        // ввод
	friend ostream& operator<<(ostream& os, const Pair&);  // вывод
};

// Класс Pairs
class Pairs
{
	Pair * prs;	        // массив пар
	int length;         // размер массива
	int count;		    // количество пар в массиве

public:
	Pairs() { length = 0; count = 0; prs = nullptr; };

	Pairs& operator=(const Pairs&);                        // копирование пар
	Pairs& operator+=(const Pairs&);                       // добавление пар
	Pairs& operator+=(const Pair&);                        // добавление новой пары
	char * operator[](const int);                          // получение имени по значению
	int operator[](const char *);                          // получение значения по имени
	friend ostream& operator<<(ostream& os, const Pairs&); // вывод
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
	// вспомагательные переменные
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

// копирование пар
Pairs& Pairs::operator=(const Pairs& _p)
{
	// проверка на копирование самого себя
	if (this != &_p)
	{
		prs = new Pair[length = _p.length];
		// копирование пар
		for (int i = 0; i < length; i++)
		{
			prs[i] = _p.prs[i];
		}
		count = _p.count;
	}
	return *this;
}

// добавление пар
Pairs& Pairs::operator+=(const Pairs& _p)
{	
	Pair * tmp_prs = new Pair[length + _p.length + 1];
	// копирование пар
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

// добавление пары
Pairs& Pairs::operator+=(const Pair& _p)
{
	Pair * tmp_prs = new Pair[++length];
	if (count > 0) 
	{
		// копирование пар
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

// получение имени по значению
char* Pairs::operator[](const int _value)
{	
	for (int i = 0; i < count; i++)
	{
		if (prs[i].value == _value) // нашли искомую пару
		{
			return prs[i].name;
		}
	}
	return "not found";
}

// получение значения по имени
int Pairs::operator[](const char* _name)
{
	int res = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(prs[i].name, _name) == 0) // нашли искомую пару
		{
			res = prs[i].value;
			break;
		}
	}
	return res;
}

// вывод
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

	// добавление пары
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

	// ожидание ввода чтобы не закрылось окно
	_getch();

	return 0;
}
