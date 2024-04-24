#include <iostream>

using namespace std;

int dodaj(int *a, int *b)
{
    int wynik = *a + *b;
    return wynik;
}

int main()
{
    int liczba1 = 2;
    int liczba2 = 3;
    cout << dodaj(&liczba1,&liczba2);
    return 0;
}
