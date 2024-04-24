#include <iostream>

int main()
{
	struct Cache
	{
		int L1;
		int L2;
		int L3;
	};

	struct Procesor
	{
		char firma[20];
		char model[20];
		float taktowanie;
		int liczba_rdzeni;
		struct Cache;
		struct Procesor* następny;

	};

	struct Procesory
	{
		struct Procesor* pierwszy;
		int liczba_procesorow;
	};
}