// ulamek.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

struct Ulamek
{
	float licznik;
	float mianownik;
	struct Ulamek* nastepny;
	struct Ulamek* poprzedni;
};

struct Ulamki
{
	struct Ulamek* poczatek;
	struct Ulamek* koniec;
};

Ulamek* usunZkonca(struct Ulamki* ulamki)
{
	struct Ulamek* wskazanie;
	if (ulamki->poczatek->nastepny != NULL)
		ulamki->poczatek->nastepny->poprzedni = ulamki->poczatek->poprzedni;
	else
	{
		ulamki->koniec = ulamki->poczatek->poprzedni;
		wskazanie->poprzedni =  ulamki->koniec;
		if (ulamki->koniec != NULL)
			ulamki->koniec->nastepny = wskazanie;
		else
			ulamki->poczatek = wskazanie;
		wskazanie->nastepny = NULL;
		ulamki->koniec = wskazanie;
	}
	return wskazanie;
}

int main()
{
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
