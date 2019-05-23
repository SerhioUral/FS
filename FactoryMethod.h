#pragma once
#include "Iterator.h"
#include "FS_EXFAT.h"
#include "FS_NTFS.h"
#include "FS_FAT32.h"

typedef struct
{
	BYTE Padding[3];
	BYTE OEM_ID[8];
} Abstract_Record;

class FactoryMethod
{
public:
	static AbstractFS *NewFSItem(WCHAR *fileName);
	static Iterator GetIterator(AbstractFS *FS);
};
