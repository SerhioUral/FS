#pragma once
#include "AbstractFS.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_ID[8];
	BYTE SectorSize[2];
	BYTE SectorsInCluster;
	BYTE Padding2[26];
	ULONGLONG SectorCount;
} NTFS_BootRecord;

class FS_NTFS : public AbstractFS
{
public:
	FS_NTFS(HANDLE fileHandle, BYTE *FSBootRecord);
	~FS_NTFS();
	virtual void AbstractFunction();
};