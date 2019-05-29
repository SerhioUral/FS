#include <iostream>
#include "FactoryMethod.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	WCHAR fileName[10];
	ULONGLONG Number;
	cout << "������� ��� ����� � �������: \\\\.\\\\���_�����:" << endl;
	wcin >> fileName;
	AbstractFS *FS = FactoryMethod::NewFSItem(fileName);
	FS->ShowInfo();
	cout << "������� ����� ��������: ";
	cin >> Number;
	Iterator iterator = FactoryMethod::GetIterator(FS);
	Decorator decorator(&iterator);
	//if (Number < FS->GetTotalClusters()) {
	//	for (iterator.First(); iterator.GetPosition() < Number; iterator.Next());
	//	iterator.GetCurrent();
	//}
	//else {
	//	cout << "������� ������� �����." << endl;
	//}
	if (Number < FS->GetTotalClusters()) {
		for (decorator.First(); decorator.GetPosition() < Number; decorator.Next());
		decorator.GetCurrent();
	}
	else {
		cout << "������� ������� �����." << endl;
	}
	system("pause");
}