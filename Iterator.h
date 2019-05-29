#pragma once
#include "AbstractFS.h"

class Iterator
{
protected:
	AbstractFS *FS;
	ULONGLONG currentOffset;
public:
	Iterator(AbstractFS *fileSystem);
	Iterator();
	Iterator::Iterator(Iterator *it);
	void First();
	void Next();
	bool IsDone();
	ULONGLONG GetPosition();
	BYTE *GetCurrent();
};