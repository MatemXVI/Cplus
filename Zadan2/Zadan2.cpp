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

const int maxStudentow = 50;

struct Ocena
{
	int ocena;	// wartosc oceny * 10
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
	Student studenci[maxStudentow];
	int liczba_studentow;
};

//float konwersja(Ocena* ocena)
//{
//	.ocena = .ocena * 10 + .liczba_dziesietna;
//	float ocenka = static_cast<float>(.ocena);
//	ocenka = ocenka / 10;
//	return ocenka;
//}


float obliczSredniaOcen(Oceny* oceny)
{
	float srednia;
	srednia = 0;
	for (int i = 0; i < oceny->liczbaOcen; i++)
	{
		srednia =+ oceny->oceny[i].ocena;
	}
	srednia = srednia / 10;
	return srednia;
}

bool wczytaj_ocene(Ocena* ocena)
{
	char kropka;
	int liczba_calkowita;
	int liczba_dziesietna;
	do
	{
		std::cin >> liczba_calkowita >> kropka >> liczba_dziesietna;
	} while ((kropka != '.') || (liczba_calkowita > 5 || liczba_calkowita < 0 || (liczba_calkowita == 5 && liczba_dziesietna != 0)) || (liczba_dziesietna != 0 && liczba_dziesietna != 5 && liczba_dziesietna != 50));
	ocena->ocena = liczba_calkowita * 10 + liczba_dziesietna;
	return true;
}


bool wczytaj_oceny(Oceny* oceny)
{
	do
	{
		std::cout << "Podaj liczbe ocen: ";
		std::cin >> oceny->liczbaOcen;
		if (std::cin.fail())
			return false;
		if (oceny->liczbaOcen <= 0 || oceny->liczbaOcen > 5)
		{
			std::cout << "Podales zla liczbe ocen. ";
		}
	}while (oceny->liczbaOcen <= 0 || oceny->liczbaOcen > 5);

	for (int n = 0; n < oceny->liczbaOcen; n++)
	{
		std::cout << "Podaj ocene nr: " << n + 1 << " z dokladnoscia do 0.5: ";
		wczytaj_ocene(&oceny->oceny[n]);
	}
	return true;
}

bool wczytaj_studenta(Student* student, int i)
{
	std::cout << "Podaj imie i nazwisko ucznia nr " << i + 1 << ": ";
	std::cin >> student->imie >> student->nazwisko;
	wczytaj_oceny(&student->oceny);
	if (std::cin.fail())
		return false;
	if (!wczytaj_oceny(&student->oceny))
		return false;
	student->srednia = obliczSredniaOcen(&student->oceny);
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
	if (ilosc_studentow >= maxStudentow || ilosc_studentow <= 0)
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

void posortuj_studentow(Studenci* studenci)
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

void wyswietl_studentow(Studenci* studenci)
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
	posortuj_studentow(&studenci);
	wyswietl_studentow(&studenci);

}