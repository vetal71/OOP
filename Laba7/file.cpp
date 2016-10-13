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

	
	h = CreateFile(ptr,          // имя файла
			GENERIC_WRITE,          // флаг записи
			0,                      // не расшаривать
			NULL,                   // безопасность
			CREATE_ALWAYS,          // всегда создание
			FILE_ATTRIBUTE_NORMAL,  // нормальный файл
			NULL);                  // без шаблона

	// генерируем исключение если хэндл не получен
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

	// генерируем исключение если хэндл не получен
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
	// проверка соответствия размера записанных данных прочитанным
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
	// проверка соответствия размера записанных данных прочитанным
	if (count != dwTemp)
	{
		throw WriteException(hf, "Incorrect data writing...");
	}

}
