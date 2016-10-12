#include "exceptions.h"

FileException::FileException(char* fname)
{
	strcpy_s(filename, sizeof filename, fname);
}

FileException::FileException(HANDLE hf)
{
	hfile = hf;
}

char* FileException::Message()
{
	char * err = "";
	strcat_s(err, sizeof err, "Undefined file exception error. File: ");
	strcat_s(err, sizeof err, filename);
	return err;
}

const char* FileException::GetFileName() const
{
	return filename;
}

char* CreateException::Message()
{
	char * err = "";
	strcat_s(err, sizeof err, "Create file exception error. File: ");
	strcat_s(err, sizeof err, GetFileName());
	return err;
}

char* ReadException::Message()
{
	char * err = "";
	strcat_s(err, sizeof err, "Read file exception error. File: ");
	strcat_s(err, sizeof err, GetFileName());
	return err;
}

char* WriteException::Message()
{
	char * err = "";
	strcat_s(err, sizeof err, "Write file exception error. File: ");
	strcat_s(err, sizeof err, GetFileName());
	return err;
}