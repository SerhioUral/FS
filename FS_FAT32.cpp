#include "FS_FAT32.h"

FS_FAT32::FS_FAT32(HANDLE fileHandle, BYTE *FSBootRecord) : AbstractFS(fileHandle)
{
	FAT32_BootRecord *bootRecord = (FAT32_BootRecord*)FSBootRecord;
	SectorsPerCluster = bootRecord->SectorsPerCluster;
	BytesPerSector = *((WORD*)bootRecord->BytesPerSector);
	BytesPerCluster = BytesPerSector *SectorsPerCluster;
	memcpy(FSName, bootRecord->OEM_ID, sizeof(FSName));
	TotalClusters = bootRecord->TotalSectors / SectorsPerCluster;
}

void FS_FAT32::AbstractFunction() {}