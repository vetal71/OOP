#include <windows.h>

class File
{
public:
	HANDLE CreateFileEx(char *);                       // �������� ������ ����� (R/W)
	HANDLE OpenFileEx(char *);                          // �������� ������������� ����� (R/W)	
	void ReadFileE(HANDLE hf, void * buf, int count);  // ������ ������ �� ����� 	
	void WriteFileEx(HANDLE hf, void * buf, int count); // ������ ������ � ����
};