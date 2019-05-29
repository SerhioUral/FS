#include "Decorator.h"

Decorator::Decorator(Iterator *it) : iterator(it)
{
}

void Decorator::First()
{
	iterator->First();
}

void Decorator::Next()
{
	iterator->Next();
	iterator->Next();
}
bool Decorator::IsDone()
{
	return iterator->IsDone();
}

ULONGLONG Decorator::GetPosition()
{
	return iterator->GetPosition();
}

BYTE *Decorator::GetCurrent()
{
	return iterator->GetCurrent();
}