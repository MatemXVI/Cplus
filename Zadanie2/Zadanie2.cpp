/*
 Wczytanie studentów
  - okreslenie liczby studentow
  - wczytanie informacji o studencie
	- wczytanie informacji o imieniu
	- wczytanie informacji o nazwisku
	- wczytanie ocen studenta
		- wczytanie oceny
			- sprawdzenie poprawności formatu oceny
			- zapisanie oceny w formacie wewnętrznym programu(int)

 Obliczenie średniej ocen studenta

 Posortuj studentow według średniej (sortowanie przez wybieranie)
	-porówynwanie dwóch studentów(porównywanie średniej)

  Wyświetlenie informacji  o maksymalnie  50 studentach
	- Wyświetlenie informacji o pojedyńczym studencie
	- wyświetlenie imienia, nazwiska


*/


#include <iostream>

const int MAX_LISTA = 50;

struct Ocena
{
	int ocena;
	int ocena_dziesietna;
	float ocena_skonwertowana;
};

struct Oceny
{
	Ocena oceny[5];
	int liczbaOcen;
};
struct Student
{
	char imie[15];
	char nazwisko[15];
	Oceny oceny;
	float srednia;
};
struct Studenci
{
	Student studenci[MAX_LISTA];
	int liczba_studentow;
};

float konwersja(Oceny* oceny, int n)
{
	oceny->oceny[n].ocena = oceny->oceny[n].ocena * 10 + oceny->oceny[n].ocena_dziesietna;
	float ocenka = static_cast<float>(oceny->oceny[n].ocena);
	ocenka = ocenka / 10;
	return ocenka;
}

float wczytaj_ocene(Oceny* oceny)
{
	char kropka;
	float suma_ocen = 0;
	std::cout << "Podaj liczbe ocen: ";
	std::cin >> oceny->liczbaOcen;
	for (int n = 0; n < oceny->liczbaOcen; n++)
	{
		std::cout << "Podaj ocene nr: " << n + 1 << " z dokladnoscia do 0.5: ";
		std::cin >> oceny->oceny[n].ocena >> kropka >> oceny->oceny[n].ocena_dziesietna;
		suma_ocen += oceny->oceny[n].ocena;
		while (kropka != '.')
		{
			std::cout << "Podales ocene bez kropki. Podaj ocene jeszcze raz: ";
			std::cin >> oceny->oceny[n].ocena >> kropka >> oceny->oceny[n].ocena_dziesietna;
		}
		while (oceny->oceny[n].ocena > 5 || oceny->oceny[n].ocena < 0 || (oceny->oceny[n].ocena == 5 && oceny->oceny[n].ocena_dziesietna != 0))
		{
			std::cout << "Podales zla ocene. Podaj jeszcze raz ocene nr " << n + 1 << ": ";
			std::cin >> oceny->oceny[n].ocena >> kropka >> oceny->oceny[n].ocena_dziesietna;
		}


		while (oceny->oceny[n].ocena_dziesietna != 0 && oceny->oceny[n].ocena_dziesietna != 5 && oceny->oceny[n].ocena_dziesietna != 50)
		{
			std::cout << "Podales zla ocene. Podaj jeszcze raz czesc dziesietna: " << oceny->oceny[n].ocena << ".";
			std::cin >> oceny->oceny[n].ocena_dziesietna;
		}
		suma_ocen += oceny->oceny[n].ocena_skonwertowana;
	}
	return suma_ocen;
}

bool wczytaj_studenta(Student* studenci, int i)
{
	std::cout << "Podaj imie i nazwisko ucznia nr " << i + 1 << ": ";
	std::cin >> studenci->imie >> studenci->nazwisko;
	studenci->srednia = wczytaj_ocene(&studenci->oceny) / 5;
	return true;
}

bool wczytaj_studentow(Studenci* studenci)
{
	studenci->liczba_studentow = 0;
	int ilosc_studentow;
	std::cout << "Podaj liczbe studentow: ";
	std::cin >> ilosc_studentow;
	if (std::cin.fail())
		return false;
	if (ilosc_studentow >= MAX_LISTA || ilosc_studentow <= 0)
	{
		return false;
	}
	for (int i = 0; i < ilosc_studentow; i++)
	{
		if (!wczytaj_studenta(&studenci->studenci[i], i))
			return false;
	}
	studenci->liczba_studentow = ilosc_studentow;
	return true;
}

void posortuj_st(Studenci* studenci)
{
	int k;
	for (int i = 0; i < studenci->liczba_studentow; i++)
	{
		k = i;
		for (int j = i + 1; j < studenci->liczba_studentow; j++)
			if (studenci->studenci[j].srednia > studenci->studenci[k].srednia)
				k = j;

		std::swap(studenci->studenci[k], studenci->studenci[i]);
	}
}

void wyswietl_st(Studenci* studenci)
{
	for (int i = 0; i < studenci->liczba_studentow; i++)
	{
		std::cout << studenci->studenci[i].imie << " " << studenci->studenci[i].nazwisko << " " << studenci->studenci[i].srednia << std::endl;
	}
}

int main()
{
	struct Studenci studenci;
	wczytaj_studentow(&studenci);
	posortuj_st(&studenci);
	wyswietl_st(&studenci);

}