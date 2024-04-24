#include <iostream>
using namespace std;
struct Studenci
    {
        string imie;
        string nazwisko;
        float oceny[5];
        float srednia;
    } student[50];


void sort_proste_wybieranie(struct Studenci student[], int ile)
{
    struct Studenci pom;
    int i, j, i_pom;
    for (i = 0; i < ile - 1; ++i)
    {
        i_pom = i;
        for (j = i+1; j<ile; ++j)
            if (swap(student[j], student[i_pom]))
                i_pom = j;
        if (i_pom != i)
        {
            pom = student[i_pom];
            student[i_pom] = student[i];
            student[i] = pom;
        }
    }
}

int main()
{
    int ile=2;


    for (int i=0; i<=ile; i++)
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

    for(int i=0; i<=ile; i++)
    {
        cout<<student[i].imie<<" "<<student[i].nazwisko<<" "<<student[i].srednia<<endl;
    }

    return 0;
}

