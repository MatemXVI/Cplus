


#include <iostream>

const int maxStudentow = 50;

struct Ocena
{
	int ocena;
};

struct Oceny
{
	Ocena oceny[5];
	int liczbaOcen;
	float srednia;
};

struct Student
{
	char imie[15];
	char nazwisko[15];
	Oceny oceny;

};

struct Studenci
{
	Student studenci[maxStudentow];
	int liczba_studentow;
};



bool wczytaj_ocene(Ocena* ocena)
{
	char kropka;
	int liczba_calkowita;
	int liczba_dziesietna;
	do
	{
		std::cin >> liczba_calkowita >> kropka >> liczba_dziesietna;
		if (kropka != '.')
			std::cout << "Nie podales kropki. ";
		if (liczba_calkowita > 5 || liczba_calkowita < 0 || (liczba_calkowita == 5 && liczba_dziesietna != 0) || (liczba_dziesietna != 0 && liczba_dziesietna != 5 && liczba_dziesietna != 50))
		{
			std::cout << "Podales zla ocene. Podaj jeszcze raz ocene: ";
		}
	} while ((kropka != '.') || liczba_calkowita > 5 || liczba_calkowita < 0 || (liczba_calkowita == 5 && liczba_dziesietna != 0) || (liczba_dziesietna != 0 && liczba_dziesietna != 5 && liczba_dziesietna != 50));
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
	} while (oceny->liczbaOcen <= 0 || oceny->liczbaOcen > 5);

	int sumaOcen = 0;
	for (int n = 0; n < oceny->liczbaOcen; n++)
	{
		std::cout << "Podaj ocene nr: " << n + 1 << " z dokladnoscia do 0.5: ";
		if (!wczytaj_ocene(&oceny->oceny[n]))
			return false;
		sumaOcen += oceny->oceny[n].ocena;
	}
	if (oceny->liczbaOcen != 0)
	{ 
		oceny->srednia = (float)sumaOcen / (float)(oceny->liczbaOcen);
		oceny->srednia = oceny->srednia/10;
	}	
	else
		oceny->srednia = 0;
	return true;
}

bool wczytaj_studenta(Student* student, int i)
{
	std::cout << "Podaj imie i nazwisko ucznia nr " << i + 1 << ": ";
	std::cin >> student->imie >> student->nazwisko;
	if (std::cin.fail())
		return false;
	if (!wczytaj_oceny(&student->oceny))
		return false;
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
			if (studenci->studenci[j].oceny.srednia > studenci->studenci[k].oceny.srednia)
				k = j;

		std::swap(studenci->studenci[k], studenci->studenci[i]);
	}
}

void wyswietl_studenta(Student *student)
{
	std::cout << student->imie << " " << student->nazwisko << " " << student->oceny.srednia << std::endl;
}



void wyswietl_studentow(Studenci* studenci)
{
	for (int i = 0; i < studenci->liczba_studentow; i++)
	{
		wyswietl_studenta(&studenci->studenci[i]);
	}
}

int main()
{
	struct Studenci studenci;
	if (!wczytaj_studentow(&studenci))
	{
		return 0;
	}
	posortuj_studentow(&studenci);
	wyswietl_studentow(&studenci);
	return 0;
}
