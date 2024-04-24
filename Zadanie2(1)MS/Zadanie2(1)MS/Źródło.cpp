/*
 Wczytanie studentów
  - okreslenie liczby studentow
  - wczytanie informacji o studencie
	- wczytanie informacji o imieniu
	- wczytanie informacji o nazwisku
	- wczytanie ocen studenta
		- wczytanie oceny
			- sprawdzenie poprawnoœci formatu oceny
			- zapisanie oceny w formacie wewnêtrznym programu(int)

 Obliczenie œredniej ocen studenta

 Posortuj studentow wed³ug œredniej (sortowanie przez wstawianie)
	-porówynwanie dwóch studentów(porównywanie œredniej)

  Wyœwietlenie informacji  o maksymalnie  50 studentach
	- Wyœwietlenie informacji o pojedyñczym studencie
	- wyœwietlenie imienia, nazwiska
*/

#include <iostream>
#include <string>
#include <cstdlib>

struct Student
{
	char imie[15];
	char nazwisko[15];
	struct Ocena oceny;
	float srednia;
};
struct Studenci
{
	Student studenci[50];
	int liczba_studentow;
};
struct Ocena
{
	int ocena;
	int ocena_dziesietna;
}




void wczytaj_st(struct Studenci* studenci)
{
	std::cout << "Podaj liczbe studentow: ";
	std::cin >> studenci->liczba_studentow;
	for (int i = 0; i <= studenci->liczba_studentow - 1; i++)
	{
		std::cout << "Podaj imie i nazwisko ucznia nr " << i + 1 << ": ";
		std::cin >> studenci->studenci[i].imie >> studenci->studenci[i].nazwisko;
		float suma_ocen = 0;
		for (int n = 0; n <= 4; n++)
		{
			std::cout << "Podaj ocene nr " << n + 1 << ": ";
			std::cin >> studenci->studenci[i].oceny[n];
			while (studenci->studenci[i].oceny[n] > 5 || studenci->studenci[i].oceny[n] < 0)
			{
				std::cout << "Podales zla ocene. Podaj jeszcze raz ocene nr " << n + 1 << ": ";
				std::cin >> studenci->studenci[i].oceny[n];
			}
			/*studenci->studenci[i].oceny[n] = studenci->studenci[i].oceny[n] * 10;
			int ocena_int = static_cast<int>(studenci->studenci[i].oceny[n]);
			if (ocena_int % 5 != 0)
			{
				std::string ocena_str = std::to_string(ocena_int);
				int dlugosc = ocena_str.length();
				if (ocena_str[dlugosc] == '1' || ocena_str[dlugosc] == '2' || ocena_str[dlugosc] == '6' || ocena_str[dlugosc] == '7')
				{
					std::cout << ocena_str;
					while (ocena_int % 5 == 0)
					{
						ocena_int--;
						
					}
				}
				else if (ocena_str[dlugosc] == '3' || ocena_str[dlugosc] == '4' || ocena_str[dlugosc] == '8' || ocena_str[dlugosc] == '9')
				{
					while (ocena_int % 5 == 0)
					{
						ocena_int++;
				
					}
				}

			} 
			studenci->studenci[i].oceny[n] = static_cast<float>(ocena_int);
			studenci->studenci[i].oceny[n] = studenci->studenci[i].oceny[n] / 10;
			std::cout << "Ocena wynosi" << studenci->studenci[i].oceny[n] << std::endl;*/

			suma_ocen += studenci->studenci[i].oceny[n];

		}
		studenci->studenci[i].srednia = suma_ocen / 5;
		
	}
}

void posortuj_st(struct Student studenci[], int liczba_studentow)
{
	int k;
	for (int i = 0; i < liczba_studentow; i++)
	{
		k = i;
		for (int j = i + 1; j < liczba_studentow; j++)
			if (studenci[j].srednia > studenci[k].srednia)
				k = j;

		std::swap(studenci[k], studenci[i]);
	}
}


void wyswietl_st(Studenci* studenci)
{
	for (int i = 0; i <= studenci->liczba_studentow - 1; i++)
	{
		std::cout << studenci->studenci[i].imie << " " << studenci->studenci[i].nazwisko << " " << studenci->studenci[i].srednia << std::endl;
	}
}



int main()
{
	wczytaj_st(&studenci);
	posortuj_st(&studenci.studenci[50], studenci.liczba_studentow);
	wyswietl_st(&studenci);

	return 0;
}
