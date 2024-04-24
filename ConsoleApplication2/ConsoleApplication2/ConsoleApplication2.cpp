#include <iostream>


int ocena;
int ocena_dziesietna;




int main()
{

		std::cout << "Podaj ocene: ";
		std::cin >> ocena;
		while (ocena > 5 || ocena < 0)
		{
			std::cout << "Podales zla ocene. Podaj jeszcze raz ocene: ";
			std::cin >> ocena;
		}
		if (ocena == 5)
		{
			int ocenka = 5;
			std::cout << ocenka;
		}
		else
		{
			std::cout << "Podaj dziesietna czesc oceny\n";
			std::cout << ocena << ".";
			std::cin >> ocena_dziesietna;
			while (ocena_dziesietna < 0 || ocena_dziesietna > 100)
			{
				std::cout << "Podales zla ocene. Podaj jeszcze raz ocene: ";
				std::cin >> ocena_dziesietna;
			}
			if (ocena_dziesietna % 5 != 0 || ocena_dziesietna % 10)
			{
				if (ocena_dziesietna >= 0 && ocena_dziesietna < 10)
				{
					if (ocena_dziesietna >= 3 && ocena_dziesietna <= 7)
						ocena_dziesietna = 5;
					else if (ocena_dziesietna == 8 || ocena_dziesietna == 9)
						ocena_dziesietna = 10;
					else
						ocena_dziesietna = 0;
				}

				else if (ocena_dziesietna >= 10 && ocena_dziesietna < 100)
				{
					if (ocena_dziesietna >= 30 && ocena_dziesietna <= 70)
						ocena_dziesietna = 5;
					else if (ocena_dziesietna >= 80 && ocena_dziesietna <= 90)
						ocena_dziesietna = 10;
					else
						ocena_dziesietna = 0;
				}
				ocena = ocena * 10 + ocena_dziesietna;
				float ocenka = static_cast<float>(ocena);
				ocenka = ocenka / 10;
				std::cout << ocenka;
			}
		}
}

