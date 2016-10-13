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

	
	h = CreateFile(ptr,          // ��� �����
			GENERIC_WRITE,          // ���� ������
			0,                      // �� �����������
			NULL,                   // ������������
			CREATE_ALWAYS,          // ������ ��������
			FILE_ATTRIBUTE_NORMAL,  // ���������� ����
			NULL);                  // ��� �������

	// ���������� ���������� ���� ����� �� �������
	if (INVALID_HANDLE_VALUE == h) 
	{
		throw CreateException(fname);
	}	
	return h;
}

HANDLE File::OpenFileEx(char* fname)
{
	HANDLE h;
	wchar_t w_fname[256];
	mbstowcs(w_fname, fname, strlen(fname) + 1);
	LPWSTR ptr = w_fname;

	h = CreateFile(ptr, 
			    GENERIC_READ, 
			    0, 
			    NULL, 
			    OPEN_EXISTING, 
			    FILE_ATTRIBUTE_NORMAL, 
			    NULL);		

	// ���������� ���������� ���� ����� �� �������
	if (INVALID_HANDLE_VALUE == h)
	{
		throw OpenException(fname);
	}
	
	return h;
}

void File::ReadFileE(HANDLE hf, void* buf, int count)
{
	DWORD dwTemp;
	
	if (FALSE == ReadFile(hf, buf, count, &dwTemp, NULL))
	{
		throw ReadException(hf);
	}
	// �������� ������������ ������� ���������� ������ �����������
	if (count != dwTemp)
	{
		throw ReadException(hf, "Incorrect data reading...");
	}	
}

void File::WriteFileEx(HANDLE hf, void* buf, int count)
{
	DWORD dwTemp;

	if (FALSE == WriteFile(hf, buf, count, &dwTemp, NULL))
	{
		throw WriteException(hf);
	}
	// �������� ������������ ������� ���������� ������ �����������
	if (count != dwTemp)
	{
		throw WriteException(hf, "Incorrect data writing...");
	}

}
