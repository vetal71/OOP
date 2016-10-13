//файловые исключения

#include <windows.h>
#include <iostream>
#include "file.h"
#include <conio.h>
#include "exceptions.h"

using namespace std;

int main(int argc, char* argv[])
{
	char fn[]            = "d:\\file.txt";    // наличие двойного \\ обязательно.      
	char WriteBuffer[]   = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = static_cast<DWORD>(strlen(WriteBuffer));

	File f;
	HANDLE h;
	try
	{
		// создаем файл
		cout << "Create file " << fn << "..." << endl;
		h = f.CreateFileEx(fn);
	}
	catch (CreateException& e)
	{
		cerr << e.Message() << " File:" << fn << " ErrorCode:" << GetLastError() << endl;
		return 1;
	}

	try
	{	
		// записываем данные в файл	
		cout << "Write data to file " << fn << "..." << endl;
		f.WriteFileEx(h, WriteBuffer, dwBytesToWrite);		
		cout << "Success. Write data: '" << WriteBuffer << "'" << endl;
	}
	catch (WriteException& e)
	{
		cerr << e.Message() << " File:" << fn << " ErrorCode:" << GetLastError() << endl;
		return 1;
	}

	// закрываем файл
	CloseHandle(h);

	try
	{
		// открываем на чтение
		cout << "Open file " << fn << "..." << endl;
		h = f.OpenFileEx(fn);
	}
	catch (OpenException& e)
	{
		cerr << e.Message() << " File:" << fn << " ErrorCode:" << GetLastError() << endl;
		return 1;
	}

	try
	{
		// читаем данные из файла		
		char * ReadBuffer = new char[dwBytesToWrite];
		cout << "Read data from file " << fn << "..." << endl;
		f.ReadFileE(h, ReadBuffer, dwBytesToWrite);
		// завершаем данные из буфера NULL символом
		ReadBuffer[dwBytesToWrite] = '\0';
		cout << "Success. Read data: '" << ReadBuffer << "'" << endl;
	}
	catch (ReadException& e)
	{
		cerr << e.Message() << " File:" << fn << " ErrorCode:" << GetLastError() << endl;
		return 1;
	}

	// закрываем файл
	CloseHandle(h);

	_getch();

	return 0;

}
