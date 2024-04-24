#include <iostream>
using namespace std;



int main()
{
    struct Student
    {
        char imie[15];
        char nazwisko[15];
        int oceny[5];
        float srednia;
    };
    struct Studenci
    {
        Student studenci[50];
        int liczba_studentow;
    };
    struct Studenci *ktos = &Student->studenci;

    void wczytaj_st(&studenci)
    {
        cout<<"Podaj liczbe studentow"
        for (int i=0; i<=Studenci.liczba_studentow; i++)
    {
        cout<<"Podaj imie ucznia nr "<<i+1<<": ";
        cin>>student[i].imie;
        cout<<"Podaj nazwisko ucznia nr "<<i+1<<": ";
        cin>>student[i].nazwisko;
        float suma_ocen = 0;
        for(int n=0; n<=4; n++)
        {
            cout<<"Podaj ocene nr "<<n+1<<": ";
            cin>>student[i].oceny[n];
            while(student[i].oceny[n]>5 || student[i].oceny[n]<0 )
            {
                cout<<"Podales zla ocene. Podaj jeszcze raz ocene nr "<<n+1<<": ";
                cin>>student[i].oceny[n];
            }
            suma_ocen += student[i].oceny[n];
        }
        student[i].srednia = suma_ocen/5;
    }

    }

    return 0;
}

