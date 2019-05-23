#pragma once
#include "AbstractFS.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_ID[8];
	BYTE Padding2[61];
	ULONGLONG TotalSectors;
	DWORD FATStartSector;
	DWORD FATSizeInSectors;
	DWORD ClusterOffset;
	DWORD TotalClusters;
	DWORD RootDirCluster;
	BYTE Padding3[8];
	BYTE SectorFactor;
	BYTE ClusterFactor;
} EXFAT_BootRecord;

class FS_EXFAT : public AbstractFS
{
public:
	FS_EXFAT(HANDLE fileHandle, BYTE *FSBootRecord);
	~FS_EXFAT();
	virtual void AbstractFunction();
};