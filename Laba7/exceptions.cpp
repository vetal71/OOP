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
	const char * s_exc = "Undefined file exception error. File: ";
	const char * fname = GetFileName();

	char *err = new char[strlen(s_exc) + strlen(fname) + 1];
	strcpy(err, s_exc);
	strcat(err, fname);
	return err;
}

const char* FileException::GetFileName() const
{
	return filename;
}

char* CreateException::Message()
{
	const char * s_exc = "Create file exception error. File: ";	
	const char * fname = GetFileName();

	char *err = new char[strlen(s_exc) + strlen(fname) + 1];
	strcpy(err, s_exc);
	strcat(err, fname);	
	return err;	
}


char* OpenException::Message()
{
	const char * s_exc = "Open file exception error. File: ";
	const char * fname = GetFileName();

	char *err = new char[strlen(s_exc) + strlen(fname) + 1];
	strcpy(err, s_exc);
	strcat(err, fname);
	return err;
}

char* ReadException::Message()
{
	return "Read file exception error.";		
}

char* WriteException::Message()
{
	return "Write file exception error.";
}