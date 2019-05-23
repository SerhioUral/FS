#include "FactoryMethod.h"

AbstractFS *FactoryMethod::NewFSItem(WCHAR *fileName)
{
	setlocale(LC_ALL, "Russian");
	HANDLE fileHandle = CreateFileW(fileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fileHandle == INVALID_HANDLE_VALUE) {
		cout << "Не удалось создать обработчик.";
		exit(GetLastError());
	}
	LARGE_INTEGER clusterOffset;
	DWORD bytesToRead;
	DWORD bytesRead;
	clusterOffset.QuadPart = 0;
	bytesToRead = 512;
	BYTE *buffer = new BYTE[bytesToRead];
	ULONGLONG currentPosition = SetFilePointer(fileHandle, clusterOffset.LowPart, &clusterOffset.HighPart, FILE_BEGIN);
	if (currentPosition != clusterOffset.LowPart) {
		cout << "Не удалось установить указатель." << endl;
		exit(GetLastError());
	}
	bool readResult = ReadFile(fileHandle, buffer, bytesToRead, &bytesRead, NULL);
	if (!readResult || bytesRead != bytesToRead) {
		cout << "Не удалось прочитать файл." << endl;
		exit(GetLastError());
	}
	Abstract_Record *record = (Abstract_Record*)buffer;
	if (strcmp((const char*)record->OEM_ID, "NTFS    ") == 0) {
		return new FS_NTFS(fileHandle, buffer);
	}
	else if (strcmp((const char*)record->OEM_ID, "EXFAT   ") == 0)
	{
		return new FS_EXFAT(fileHandle, buffer);
	}
	else if (strcmp((const char*)record->OEM_ID, "MSDOS5.0") == 0 )
	{
		return new FS_FAT32(fileHandle, buffer);
	}
	else
	{
		cout << "Файловая система не поддерживается.";
		exit(-1);
	}

}

Iterator FactoryMethod::GetIterator(AbstractFS *FS)
{
	return Iterator(FS);
}
