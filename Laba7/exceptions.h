#include "windows.h"

class FileException
{
	HANDLE hfile;	    // дескриптор файла
	char filename[256];	// имя файла
public:
	FileException(char * fname);
	FileException(HANDLE hf);
	virtual char * Message();
	// доступ к полю filename
	const char * GetFileName() const;
};

//ошибка при создании файла
class CreateException : public FileException
{
public:
	CreateException(char * fname) : FileException(fname) {};
	char* Message() override;
};

//ошибка открытия файла
class OpenException : public FileException
{
public:
	OpenException(char * fname) : FileException(fname) {};
	char* Message() override;
};

//ошибка чтения
class ReadException : public FileException
{
	char * msg;
public:
	ReadException(HANDLE h) : FileException(h) { msg = {0}; };
	ReadException(HANDLE h, char* _msg) : FileException(h) { strcpy_s(msg, sizeof msg, _msg); };
	char* Message() override;
};
//ошибка записи
class WriteException : public FileException
{
	char * msg;
public:
	WriteException(HANDLE h) : FileException(h) { msg = { 0 }; };
	WriteException(HANDLE h, char* _msg) : FileException(h) { strcpy_s(msg, sizeof msg, _msg); };
	char* Message() override;
};