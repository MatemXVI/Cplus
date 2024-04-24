// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string.h>

using namespace std;

struct Osoba
{
	char nazwisko[30];
	char imie[12];
	struct data_urodzenia;
}osoby[30];

struct Osoba *ludzie = &osoby[0];

bool poprzedza(struct Osoba o1, struct Osoba o2)
{
	return strcmp(o2.nazwisko, o1.nazwisko) >= 0;
}

void sort_proste_wybieranie(struct Osoba osoby[], int ile)
{
	struct Osoba pom; int i, j, i_pom;
	for (i = 0; i < ile - 1; ++i)
	{
		i_pom = i;
			for (j = i + 1; j < ile; ++j)
				if (poprzedza(osoby[j], osoby[i_pom]))
					i_pom = j;
		if (i_pom != i)
		{
			pom = osoby[i_pom];
			osoby[i_pom] = osoby[i];
			osoby[i] = pom;
		}
	}
}

int main()
{
	cout << "Podaj imie i nazwisko o1 ";
	cin >>osoby[0].imie>> osoby[0].nazwisko;
	cout << "Podaj imie i nazwisko o2";
	cin >> osoby[1].imie >> osoby[1].nazwisko;
	sort_proste_wybieranie(ludzie, 2);

	cout << osoby[0].imie << osoby[0].nazwisko<<endl;
	cout << osoby[1].imie << osoby[1].nazwisko << endl;

	
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
