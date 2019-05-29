#include "Iterator.h"

class Decorator : public Iterator
{
private:
	Iterator * iterator;
public:
	Decorator(Iterator *it);
	void First();
	void Next();
	bool IsDone();
	ULONGLONG GetPosition();
	BYTE *GetCurrent();
};