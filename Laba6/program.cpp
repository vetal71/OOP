#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

template <class T1, class T2>
struct Pair
{
	T1 key;		        // имя
	T2 value;	        // значение	  
	
	Pair<T1, T2>& operator=(const T1);
	Pair<T1, T2>& operator=(const T2);

	template <class T1, class T2> friend istream& operator>>(istream& is, Pair<T1, T2>&);        // ввод
	template <class T1, class T2> friend ostream& operator<<(ostream& os, const Pair<T1, T2>&);  // вывод
};

template <class T1, class T2> class Pairs
{
	Pair<T1, T2> * prs;	// массив пар
	int length;		    // размер массива
	int count;		    // количество имеющихся пар в массиве

public:
	Pairs() { length = 0; count = 0; prs = nullptr; };
	Pairs(int);
	~Pairs();

	Pairs<T1, T2>& operator+=(const Pair<T1, T2>&);
	template <class T1, class T2> friend ostream& operator<<(ostream& os, Pairs<T1, T2>&);
};

template <class T1, class T2> Pair<T1, T2>& Pair<T1, T2>::operator=(const T1 _key)
{
	key = _key;
	return *this;
}

template <class T1, class T2> Pair<T1, T2>& Pair<T1, T2>::operator=(const T2 _value)
{
	value = _value;
	return *this;
}


template <class T1, class T2> istream& operator>>(istream& is, Pair<T1, T2>& _p)
{
	// очистим входной поток
	is.clear();
	
	T1 _key;
	T2 _value;
	cout << "Enter key: ";
	is >> _key;
	cout << "Enter value:";
	is >> _value;

	_p.key = _key;
	_p.value = _value;
	
	return is;
}

template <class T1, class T2> ostream& operator<<(ostream& os, const Pair<T1, T2>& _p)
{
	os << setw(15) << _p.key << setw(10) << _p.value << endl;
	return os;
}

template <class T1, class T2> Pairs<T1, T2>::Pairs(int _length)
{
	length = _length;
	prs = new Pair<T1, T2>[_length];	
	count = 0;
}


template <class T1, class T2>
Pairs<T1, T2>::~Pairs()
{
	delete[] prs;
}

template <class T1, class T2> Pairs<T1, T2>& Pairs<T1, T2>::operator+=(const Pair<T1, T2>& _p)
{
	Pair<T1, T2> * tmp_prs = new Pair<T1, T2>[++length];
	if (count > 0)
	{
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


template <class T1, class T2> ostream& operator<<(ostream& os, Pairs<T1, T2>& _p)
{
	os << "------------------------------------------" << endl;
	os << setw(15) << "Key" << setw(10) << "Value" << endl;
	os << "------------------------------------------" << endl;
	for (int i = 0; i < _p.length; i++)
	{
		os << _p.prs[i];
	}
	os << "------------------------------------------" << endl;
	return os;
}

int main(int argc, char* argv[])
{
	Pairs<char*, int> pairs;
	Pair<char*, int> p1, p2, p3; //p4

	p1 = "Tom";
	p1 = 3000;
	p2 = "Sarah";
	p2 = 2000;
	p3 = "Jack";
	p3 = 4000;

	//cin >> p4;  // ошибка !!!

	pairs += p1;
	pairs += p2;
	pairs += p3;

	cout << pairs;
	
	_getch();

	return 0;
}

