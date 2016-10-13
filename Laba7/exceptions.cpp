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
	return "Create file exception error.";	
}


char* OpenException::Message()
{
	return "Open file exception error.";	
}

char* ReadException::Message()
{
	if (strlen(msg) == 0) {
		return "Read file exception error.";
	}
	else
	{
		return msg;
	}
}

char* WriteException::Message()
{
	if (strlen(msg) == 0) {
		return "Write file exception error.";
	}
	else
	{
		return msg;
	}
}
