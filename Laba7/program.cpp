//�������� ����������
#include <windows.h>
#include <iostream>

using namespace std;




int main(int argc, char* argv[])
{
	// CreateFile(szName, dwAccess, dwShareMode, lpSecurityAttributes,
	// dwCreationDisposition, dwFlags, hTemplateFile);
	/*
	 * � Windows ��� ����, ����� ������� ��� ������� ����, ����� ������� ���������, 
	 * ������� ����� ���� ����������. � �������, ����������� �� ��� ���������� ������������ ������ �����. 
	 * �������� szName ������ ��� �����, � dwAccess � �������� ������ � �����, 
	 * ������ ��� GENERIC_READ, GENERIC_WRITE ��� ��� ��������, ������������ ���������� ���. 
	 * �������� dwShareMode ����������, ��� ����� ������ � ������ ������ ��������, ���� �� � ��� ��������. 
	 * ��������� �������� � FILE_SHARE_READ, FILE_SHARE_WRITE, FILE_SHARE_DELETE � �� ����������, 
	 * ������ ����� ���� �������� ������ ������������� � ����. �������� dwCreationDisposition ����������, 
	 * ��� ������ �� ����� ������� ����, ����� ����, ��������, CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, OPEN_ALWAYS. 
	 * � ��������� ����� ��������� �������� ���������� ��������������. 
	 * � ������� dwFlags ����� ������� �������������� �������� �����, ��������, 
	 * ������� �� ��� � ������������� ��� ������ ����, ��� �������, ��� ���� �������� �������, 
	 * ��������� ��� ���������. ������ ���� �������� FILE_ATTRIBUTE_NORMAL. 
	 * �������, ��� lpSecurityAttributes � hTemplateFile ������ ����� �� �����, ���� ����� ����� ���������� NULL
	 */

	// ReadFile(hFile, lpBuff, dwBuffSize, &dwCount, NULL);

	// WriteFile(hFile, lpBuff, dwBuffSize, &dwCount, NULL);

	try
	{
		
	}
	catch (...)
	{
	}
	

}
