#include <windows.h>

class File
{
	HANDLE CreateFile(char *);                        // создание нового файла (R/W)
	HANDLE OpenFile(char *);                          // открытие существующего файла (R/W)	
	void ReadFile(HANDLE hf, void * buf, int count);  // чтение данных из файла 	
	void WriteFile(HANDLE hf, void * buf, int count); // запись данных в файл
};