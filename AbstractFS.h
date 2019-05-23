#pragma once
#include <windows.h>
#include <locale>
#include <iostream>

using namespace std;

class AbstractFS
{
protected:
	HANDLE FileHandle;
	BYTE FSName[8];
	DWORD BytesPerSector;
	DWORD SectorsPerCluster;
	DWORD BytesPerCluster;
	DWORD TotalClusters;
	DWORD BytesRead;
	BYTE *Buffer;
public:
	AbstractFS(HANDLE fileHandle);
	~AbstractFS();
	BYTE *GetFSName();
	DWORD GetBytesPerCluster();
	DWORD GetTotalClusters();
	BYTE *GetBuffer();
	void ShowInfo();
	void ShowBuffer();
	void ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters);
	virtual void AbstractFunction() = 0;
};