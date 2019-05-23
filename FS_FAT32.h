#pragma once
#include "AbstractFS.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_ID[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster;
	BYTE ReservedSectors[2];
	BYTE Padding2[16];
	ULONGLONG TotalSectors;
} FAT32_BootRecord;

class FS_FAT32 : public AbstractFS
{
public:
	FS_FAT32(HANDLE fileHandle, BYTE *FSBootRecord);
	~FS_FAT32();
	virtual void AbstractFunction();
};