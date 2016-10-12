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
	char* Message() override;
};

//ошибка чтения
class ReadException : public FileException
{
public:
	char* Message() override;
};
//ошибка записи
class WriteException : public FileException
{
public:
	char* Message() override;
};