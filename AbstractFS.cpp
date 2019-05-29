#include "AbstractFS.h"
#include <string>
#include <iostream>
#include <iomanip>

AbstractFS::AbstractFS(HANDLE fileHandle)
{
	FileHandle = fileHandle;
}

AbstractFS::~AbstractFS()
{
	CloseHandle(FileHandle);
}

BYTE *AbstractFS::GetFSName()
{
	return FSName;
}

DWORD AbstractFS::GetBytesPerCluster()
{
	return BytesPerCluster;
}

DWORD AbstractFS::GetTotalClusters()
{
	return TotalClusters;
}

BYTE *AbstractFS::GetBuffer()
{
	return Buffer;
}

void AbstractFS::ShowBuffer()
{
	for (ULONGLONG i = 0; i < BytesRead; i++)
	{

		cout << hex << setw(2) << setfill('0') << (DWORD)Buffer[i] << " ";
	}

}

void AbstractFS::ShowInfo()
{
	setlocale(LC_ALL, "Russian");
	cout << "Тип файловой системы: " << FSName << endl;
	cout << "Количество байт в секторе: " << BytesPerSector << endl;
	cout << "Количество байт в кластере: " << BytesPerCluster << endl;
	cout << "Количество кластеров: " << TotalClusters << endl;
}

void AbstractFS::ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters)
{
	Buffer = new BYTE[numberOfClusters *BytesPerCluster];
	setlocale(LC_ALL, "Russian");
	LARGE_INTEGER clusterOffset;
	DWORD bytesToRead;
	clusterOffset.QuadPart = startCluster *BytesPerCluster;
	bytesToRead = numberOfClusters *BytesPerCluster;
	ULONGLONG currentPosition = SetFilePointer(FileHandle, clusterOffset.LowPart, &clusterOffset.HighPart, FILE_BEGIN);
	if (currentPosition != clusterOffset.LowPart) {
		cout << "Не удалось установить указатель." << endl;
		exit(GetLastError());
	}
	bool readResult = ReadFile(FileHandle, Buffer, bytesToRead, &BytesRead, NULL);
	if (!readResult || BytesRead != bytesToRead) {
		cout << "Не удалось прочитать файл." << endl;
		exit(GetLastError());
	}
}