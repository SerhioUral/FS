#include "Iterator.h"

Iterator::Iterator(AbstractFS *fileSystem)
{
	FS = fileSystem;
	currentOffset = 0;
}

void Iterator::First()
{
	currentOffset = 0;
}

void Iterator::Next()
{
	currentOffset++;
}

bool Iterator::IsDone()
{
	return (currentOffset < (FS->GetTotalClusters() + 1));
}

ULONGLONG Iterator::GetPosition()
{
	return currentOffset;
}

BYTE *Iterator::GetCurrent()
{
	FS->ReadClusters(currentOffset, 1);
	FS->ShowBuffer();
	BYTE *Cluster = FS->GetBuffer();
	return Cluster;
}