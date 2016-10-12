//файловые исключения

#include <windows.h>
#include <iostream>
#include "file.h"

using namespace std;

int main(int argc, char* argv[])
{
	// ReadFile(hFile, lpBuff, dwBuffSize, &dwCount, NULL);

	// WriteFile(hFile, lpBuff, dwBuffSize, &dwCount, NULL);

	char fn[] = "d:\\file.txt";          // неверное имя файла
	char DataBuffer[] = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);

	File f;
	HANDLE h = f.CreateFileEx(fn);	

	f.WriteFileEx(h, DataBuffer, dwBytesToWrite);

	//f.OpenFileEx(fn);

	//f.ReadFileEx(h, DataBuffer, dwBytesToWrite);

	CloseHandle(h);
}

/*
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

void DisplayError(LPTSTR lpszFunction);

int main(int argc, char* argv[])
{
	HANDLE hFile;
	char DataBuffer[] = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = FALSE;

	wchar_t w_fname[256];
	char fname[] = "d:\\111.txt";
	mbstowcs(w_fname, fname, strlen(fname) + 1);
	LPWSTR ptr = w_fname;

	hFile = CreateFile(ptr,                // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		CREATE_NEW,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{
		DisplayError(TEXT("CreateFile"));
		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), argv[1]);
		return 1;
	}

	_tprintf(TEXT("Writing %d bytes to %s.\n"), dwBytesToWrite, argv[1]);

	bErrorFlag = WriteFile(
		hFile,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{
		DisplayError(TEXT("WriteFile"));
		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			// This is an error because a synchronous write that results in
			// success (WriteFile returns TRUE) should write all data as
			// requested. This would not necessarily be the case for
			// asynchronous writes.
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
		}
		else
		{
			_tprintf(TEXT("Wrote %d bytes to %s successfully.\n"), dwBytesWritten, argv[1]);
		}
	}

	CloseHandle(hFile);
	return 0;
}

void DisplayError(LPTSTR lpszFunction)
// Routine Description:
// Retrieve and output the system error message for the last-error code
{
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL);

	lpDisplayBuf =
		(LPVOID)LocalAlloc(LMEM_ZEROINIT,
			(lstrlen((LPCTSTR)lpMsgBuf)
				+ lstrlen((LPCTSTR)lpszFunction)
				+ 40) // account for format string
			* sizeof(TCHAR));

	if (FAILED(StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error code %d as follows:\n%s"),
		lpszFunction,
		dw,
		lpMsgBuf)))
	{
		printf("FATAL ERROR: Unable to output error code.\n");
	}

	_tprintf(TEXT("ERROR: %s\n"), (LPCTSTR)lpDisplayBuf);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);

}
*/