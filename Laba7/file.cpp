#include "file.h"
#include "exceptions.h"
#include <iostream>
#include <windows.h>
#include "tchar.h"

using namespace std;

HANDLE File::CreateFileEx(char* fname)
{
	HANDLE h;	
	wchar_t w_fname[256];
	mbstowcs(w_fname, fname, strlen(fname) + 1);
	LPWSTR ptr = w_fname;

	try
	{
		h = CreateFile(ptr,                // name of the write
			GENERIC_WRITE,          // open for writing
			0,                      // do not share
			NULL,                   // default security
			CREATE_NEW,             // create new file only
			FILE_ATTRIBUTE_NORMAL,  // normal file
			NULL);                  // no attr. template

		if (INVALID_HANDLE_VALUE == h) 
		{
			throw CreateException(fname);
		}
	}
	catch (CreateException& ce)
	{
		cerr << ce.Message() << endl;
	}
	return h;
}

HANDLE File::OpenFileEx(char* fname)
{
	HANDLE h = nullptr;
	wchar_t w_fname[256];
	mbstowcs(w_fname, fname, strlen(fname) + 1);
	LPWSTR ptr = w_fname;

	try
	{
		HANDLE h = CreateFile(ptr, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (INVALID_HANDLE_VALUE == h)
		{
			throw OpenException(fname);
		}
	}
	catch (OpenException& e)
	{
		cerr << e.Message() << endl;
	}
	return h;
}

void File::ReadFileEx(HANDLE hf, void* buf, int count)
{
	DWORD dwTemp;
	try
	{
		ReadFile(hf, &buf, count, &dwTemp, NULL);
		if (count != dwTemp)
		{
			throw ReadException(hf);
		}
	}
	catch(ReadException& e)
	{
		cerr << e.Message() << endl;
	}
}

void File::WriteFileEx(HANDLE hf, void* buf, int count)
{
	DWORD dwTemp;
	try
	{
		WriteFile(hf, buf, count, &dwTemp, NULL);
		if (count != dwTemp)
		{
			throw WriteException(hf);
		}
	}
	catch (WriteException& e)
	{
		cerr << e.Message() << endl;
	}
}
