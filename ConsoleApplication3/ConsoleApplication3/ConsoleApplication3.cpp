
#include <iostream>
// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
/* Podział na podproblemy:
-wczytanie maksymalnie 40 osob
-podzielenie na kobiety i mezczyzn
-wyswietlenie odrebnych list(nazwisk i imion) dla kobiet i mężczyzn uporzadkowanych alfabetycznie(za pomocą sortowania)

*/


const int MAX_LISTA = 40;
struct Osoba
{
	char nazwisko[40];
	char imie[40];

};

struct Osoby
{
	struct Osoba osoba[MAX_LISTA];
	int iloscosob;

};

bool wczytaj_Osobe(struct Osoba* osoba)
{
	std::cout << "Podaj nazwisko.\n";
	std::cin >> osoba->nazwisko;
	std::cout << "Podaj imie.\n";
	std::cin >> osoba->imie;

	return true;

};
bool wczytaj_Osoby(struct Osoby* osoby)
{
	osoby->iloscosob = 0;
	int ilosc_osob;
	std::cout << "Podaj liczbe osob.\n";
	std::cin >> ilosc_osob;
	if (std::cin.fail())
		return false;
	if (ilosc_osob<0 || ilosc_osob>MAX_LISTA)
		return false;

	for (int i = 0; i < ilosc_osob; i++)
	{
		if (!wczytaj_Osobe(&(osoby->osoba[i])))
			return false;
	}
	osoby->iloscosob = ilosc_osob;
	return true;

}

bool poprzedza(struct Osoba o1, struct Osoba o2) {
	return strcmp(o2.nazwisko, o1.nazwisko) >= 0;
}

void posortuj(struct Osoba osoby[], int iloscosob) {
	struct Osoba pom;
	int i, j;
	for (i = 1; i < iloscosob; ++i)
	{
		pom = osoby[i];
		j = i - 1;
		while (j >= 0 && poprzedza(pom, osoby[j]))
		{

			osoby[j + 1] = osoby[j];
			--j;
		}
		osoby[j + 1] = pom;


	}

}

bool czy_Kobieta(struct Osoba* osoba)
{
	if (osoba->imie == "*a")
		return true;
	else
		return false;

}

void wyswietl_Osobe(struct Osoba* osoba)
{
	std::cout << "Nazwisko=";

	std::cout << osoba->nazwisko;
	std::cout << "Imie=";
	std::cout << osoba->imie;


}



void wyswietl_Osoby(struct Osoby* osoby)
{
	for (int i = 0; i < osoby->iloscosob; i++)
	{

		wyswietl_Osobe(&(osoby->osoba[i]));
	}

}






int main()
{
	struct Osoby osoby;

	if (!wczytaj_Osoby(&osoby))
	{
		std::cout << "Niepoprawne dane.\n";
		return 0;
	}
	wyswietl_Osoby(&osoby);



}


