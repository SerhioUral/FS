#include "FS_EXFAT.h"

DWORD Power(DWORD number, DWORD pow)
{
	DWORD result = number;
	if (pow == 1) {
		return result;
	}
	else {
		for (int i = 1; i < pow; i++)
			result *= number;
	}
	return result;
}

FS_EXFAT::FS_EXFAT(HANDLE fileHandle, BYTE *FSBootRecord) : AbstractFS(fileHandle)
{
	EXFAT_BootRecord *bootRecord = (EXFAT_BootRecord*)FSBootRecord;
	TotalClusters = bootRecord->TotalClusters;
	memcpy(FSName, bootRecord->OEM_ID, sizeof(FSName));
	BytesPerSector = Power(2, bootRecord->SectorFactor);
	SectorsPerCluster = Power(2, bootRecord->ClusterFactor);
	BytesPerCluster = BytesPerSector *SectorsPerCluster;
}

void FS_EXFAT::AbstractFunction() {}