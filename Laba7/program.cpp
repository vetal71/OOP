//�������� ����������

#include <windows.h>
#include <iostream>
#include "file.h"
#include <conio.h>
#include "exceptions.h"

using namespace std;

int main(int argc, char* argv[])
{
	char fn[]            = "d:\\file.txt";    // ������� �������� \\ �����������.      
	char WriteBuffer[]   = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = static_cast<DWORD>(strlen(WriteBuffer));

	File f;
	HANDLE h;
	try
	{
		// ������� ����
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
		// ���������� ������ � ����	
		cout << "Write data to file " << fn << "..." << endl;
		f.WriteFileEx(h, WriteBuffer, dwBytesToWrite);		
		cout << "Success. Write data: '" << WriteBuffer << "'" << endl;
	}
	catch (WriteException& e)
	{
		cerr << e.Message() << " File:" << fn << " ErrorCode:" << GetLastError() << endl;
		return 1;
	}

	// ��������� ����
	CloseHandle(h);

	try
	{
		// ��������� �� ������
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
		// ������ ������ �� �����		
		char * ReadBuffer = new char[dwBytesToWrite];
		cout << "Read data from file " << fn << "..." << endl;
		f.ReadFileE(h, ReadBuffer, dwBytesToWrite);
		// ��������� ������ �� ������ NULL ��������
		ReadBuffer[dwBytesToWrite] = '\0';
		cout << "Success. Read data: '" << ReadBuffer << "'" << endl;
	}
	catch (ReadException& e)
	{
		cerr << e.Message() << " File:" << fn << " ErrorCode:" << GetLastError() << endl;
		return 1;
	}

	// ��������� ����
	CloseHandle(h);

	_getch();

	return 0;

}
