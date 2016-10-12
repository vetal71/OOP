#include <iostream>
#include <conio.h>

using namespace std;

template <class T1, class T2>
struct Pair
{
	T1 key;		        // имя
	T2 value;	        // значение	  

	friend istream& operator>>(istream&, Pair<T1, T2>&);
};

template <class T1, class T2>
istream& operator>>(istream& is, Pair<T1, T2>& _pair)
{
	is >> _pair.key >> _pair.value;
	return is;
}

int main(int argc, char* argv[])
{
	Pair<int, int> pair;

	cin >> pair;

	cout << pair.key << "=" << pair.value << endl;

	_getch();

	return 0;
}

