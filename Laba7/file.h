#include <windows.h>

class File
{
public:
	HANDLE CreateFileEx(char *);                       // создание нового файла (R/W)
	HANDLE OpenFileEx(char *);                          // открытие существующего файла (R/W)	
	void ReadFileE(HANDLE hf, void * buf, int count);  // чтение данных из файла 	
	void WriteFileEx(HANDLE hf, void * buf, int count); // запись данных в файл
};