#include "file.h"
#include "exceptions.h"
#include <iostream>

using namespace std;

HANDLE File::CreateFile(char* fname)
{
	HANDLE h = nullptr;
	try
	{
		HANDLE h = CreateFile(fname, GENERIC_READ || GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	}
	catch (CreateException(fname) )
	{
		cerr << ce.Message();
	}
	return h;
}

HANDLE File::OpenFile(char*)
{
}

void File::ReadFile(HANDLE hf, void* buf, int count)
{
}

void File::WriteFile(HANDLE hf, void* buf, int count)
{
}
