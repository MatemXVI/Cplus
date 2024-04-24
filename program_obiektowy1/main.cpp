#include <iostream>

using namespace std;

class Zwierze
{
    public:
    //atrybuty
    string gatunek;
    string imie;
    int wiek;
    //metody
    void dodaj_zwierze()
    {
        cout<<"DODAWANIE NOWEGO ZWIERZECIA DO BAZY: "<<endl;
        cout<<"Podaj gatunek: ";
        cin>>gatunek;
        cout<<"Podaj imie: ";
        cin>>imie;
        cout<<"Podaj wiek: ";
        cin>>wiek;
    }

    void daj_glos()
    {
        if(gatunek=="kot") cout<<imie<<" lat"<<wiek<<": Miau!";
        else if(gatunek=="koza") cout<<imie<<" lat"<<wiek<<": Beee!!";
        else if(gatunek=="krowa") cout<<imie<<" lat"<<wiek<<": Muuu!";
        else cout<<"Nieznany gatunek. Mo¿e jakieœ UFO!";
    }
};

int main()
{
   Zwierze z1;
   z1.dodaj_zwierze();
   z1.daj_glos();

   Zwierze z2;
   z2.dodaj_zwierze();
   z2.daj_glos();
    return 0;
}
