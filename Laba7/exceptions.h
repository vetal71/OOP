#include "windows.h"

class FileException
{
	HANDLE hfile;	    // ���������� �����
	char filename[256];	// ��� �����
public:
	FileException(char * fname);
	FileException(HANDLE hf);
	virtual char * Message();
	// ������ � ���� filename
	const char * GetFileName() const;
};

//������ ��� �������� �����
class CreateException : public FileException
{
public:
	CreateException(char * fname) : FileException(fname) {};
	char* Message() override;
};

//������ �������� �����
class OpenException : public FileException
{
public:
	OpenException(char * fname) : FileException(fname) {};
	char* Message() override;
};

//������ ������
class ReadException : public FileException
{
public:
	ReadException(HANDLE h) : FileException(h) {};
	char* Message() override;
};
//������ ������
class WriteException : public FileException
{
public:
	WriteException(HANDLE h) : FileException(h) {};
	char* Message() override;
};