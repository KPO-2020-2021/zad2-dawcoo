#include <iostream>
#include "BazaTestu.hh"

using namespace std;

int main(int argc, char **argv)
{

    LZespolona liczba1;
    liczba1.re = 2;
    liczba1.im = 3;

    LZespolona liczba2;
    liczba2.re = -2;
    liczba2.im = -3;

    LZespolona liczba3;
    liczba3.re = 2.3;
    liczba3.im = -3.1;
/*
    Wyswietl(liczba1);
    cout << endl;
    Wyswietl(liczba2);
    cout << endl;
    Wyswietl(liczba3);
    cout << endl;

    LZespolona wynik1 = liczba1 + liczba3;
    Wyswietl(wynik1);

    if (wynik1.re == 4.3 && wynik1.im == -0.1) {
        cout << "Wynik testu dodawania - OK" << endl;
    }
    else
    {
        cout << "Wynik testu dodawania - NOK" << endl;
    }
    */
    LZespolona wynik2 = liczba1 * liczba3;
    Wyswietl(wynik2);
    
    



  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
