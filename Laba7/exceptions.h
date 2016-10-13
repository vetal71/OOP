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
	char * msg;
public:
	ReadException(HANDLE h) : FileException(h) { msg = {0}; };
	ReadException(HANDLE h, char* _msg) : FileException(h) { strcpy_s(msg, sizeof msg, _msg); };
	char* Message() override;
};
//������ ������
class WriteException : public FileException
{
	char * msg;
public:
	WriteException(HANDLE h) : FileException(h) { msg = { 0 }; };
	WriteException(HANDLE h, char* _msg) : FileException(h) { strcpy_s(msg, sizeof msg, _msg); };
	char* Message() override;
};