#include <iostream>

using namespace std;

int zmienna = 123;
int * wskaznik = & zmienna;

int main()
{
    cout << *wskaznik << endl;
    return 0;
}
