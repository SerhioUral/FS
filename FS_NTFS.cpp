#include "FS_NTFS.h"

FS_NTFS::FS_NTFS(HANDLE fileHandle, BYTE *FSBootRecord) : AbstractFS(fileHandle)
{
	NTFS_BootRecord *bootRecord = (NTFS_BootRecord*)FSBootRecord;
	memcpy(FSName, bootRecord->OEM_ID, sizeof(FSName));
	BytesPerSector = *((WORD*)bootRecord->SectorSize);
	SectorsPerCluster = bootRecord->SectorsInCluster;
	BytesPerCluster = SectorsPerCluster *BytesPerSector;
	TotalClusters = bootRecord->SectorCount / SectorsPerCluster;
}

void FS_NTFS::AbstractFunction() {}