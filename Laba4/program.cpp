/*
Лабораторная работа №4
Вариант 11
Колесник Илья Витальевич

program.cpp
*/

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
	char * operator[](int);                                // получение имени по значению
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
	prs = new Pair[length += _p.length];
	// копирование пар
	for (int i = 0; i < length; i++)
	{
		prs[i] = _p.prs[i];
	}
	count += _p.count;
	return *this;
}

// добавление пары
Pairs& Pairs::operator+=(const Pair& _p)
{
	prs = new Pair[length + 1];
	count++;
	prs[count - 1] = _p.name;
	prs[count - 1] = _p.value;
	return *this;
}

// получение имени по значению
char* Pairs::operator[](int _value)
{	
	char * res = "not found";
	for (int i = 0; i < count; i++)
	{
		if (prs[i].value == _value) // нашли искомую пару
		{
			strcpy_s(res, sizeof(prs[i].name), prs[i].name);
			break;
		}
	}
	return res;
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

	// оператор ввода для пары
	pair.name = "A";
	pair.value = 1;
	
	cin >> pair;

	cout << pair;

	// добавление пары
	//pairs += pair;

	//cout << pairs;
	
	// ожидание ввода чтоб не закрылось окно
	_getch();

	return 0;
}
