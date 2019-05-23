#pragma once
#include "AbstractFS.h"

class Iterator
{
protected:
	AbstractFS *FS;
	ULONGLONG currentOffset;
public:
	Iterator(AbstractFS *fileSystem);
	void First();
	void Next();
	bool IsDone();
	ULONGLONG GetPosition();
	BYTE *GetCurrent();
};