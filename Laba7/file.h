#include <windows.h>

class File
{
	HANDLE CreateFile(char *);                        // �������� ������ ����� (R/W)
	HANDLE OpenFile(char *);                          // �������� ������������� ����� (R/W)	
	void ReadFile(HANDLE hf, void * buf, int count);  // ������ ������ �� ����� 	
	void WriteFile(HANDLE hf, void * buf, int count); // ������ ������ � ����
};