//файловые исключения
#include <windows.h>
#include <iostream>

using namespace std;




int main(int argc, char* argv[])
{
	// CreateFile(szName, dwAccess, dwShareMode, lpSecurityAttributes,
	// dwCreationDisposition, dwFlags, hTemplateFile);
	/*
	 * В Windows для того, чтобы открыть или создать файл, нужно вызвать процедуру, 
	 * имеющую целых семь аргументов. К счастью, большинство из них приходится использовать крайне редко. 
	 * Аргумент szName задает имя файла, а dwAccess — желаемый доступ к файлу, 
	 * обычно это GENERIC_READ, GENERIC_WRITE или оба значения, объединенные логическим или. 
	 * Параметр dwShareMode определяет, что могут делать с файлом другие процессы, пока мы с ним работаем. 
	 * Возможные значения — FILE_SHARE_READ, FILE_SHARE_WRITE, FILE_SHARE_DELETE и их комбинации, 
	 * однако часто этот параметр просто устанавливают в ноль. Параметр dwCreationDisposition определяет, 
	 * как именно мы хотим открыть файл, может быть, например, CREATE_NEW, CREATE_ALWAYS, OPEN_EXISTING, OPEN_ALWAYS. 
	 * О семантике этого хозяйства нетрудно догадаться самостоятельно. 
	 * С помощью dwFlags можно указать дополнительные свойства файла, например, 
	 * хранить ли его в зашифрованном или сжатом виде, или сказать, что файл является скрытым, 
	 * временным или системным. Обычно сюда передают FILE_ATTRIBUTE_NORMAL. 
	 * Наконец, про lpSecurityAttributes и hTemplateFile сейчас знать не нужно, сюда можно смело передавать NULL
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
