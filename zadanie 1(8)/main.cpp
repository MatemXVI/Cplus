#include <iostream>

using namespace std;


int main()
{

   for(int a = 1; a <= 9; a++ )
   {
        int a3=a*a*a;
        for(int b = 0; b <= 9; b++ )
        {
            int b3=b*b*b;
            for(int c = 0; c <= 9; c++ )
            {
                int c3=c*c*c;
                int wynik = a3+b3+c3;
                int liczba = 100*a+10*b+c;
                if(wynik==liczba)
                {
                    cout<<liczba<<endl;
                }
            }
        }
    }
    return 0;
}
