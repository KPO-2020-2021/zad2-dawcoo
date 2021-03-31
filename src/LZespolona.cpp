#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
	LZespolona  Wynik;

	Wynik.re = Skl1.re + Skl2.re;
	Wynik.im = Skl1.im + Skl2.im;
	return Wynik;
}

LZespolona  operator - (LZespolona  Skl1, LZespolona  Skl2) 
{
	LZespolona wynik;

	wynik.re = Skl1.re - Skl2.re;
	wynik.im = Skl1.im - Skl2.im;

	return wynik;
}

LZespolona operator * (LZespolona  Skl1, LZespolona  Skl2) 
{
	double a = Skl1.re * Skl2.re;
	double b = Skl1.im * Skl2.im*-1;
	double c = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
	LZespolona wynik;
	wynik.re = a + b;
	wynik.im = c;
	return wynik;
}
LZespolona operator / (LZespolona Skl1, double Skl2)
{
	LZespolona wynik;
	if (Skl2 == 0)
	{
		cerr << "nie wolno dzielic przez 0";
	}
	else
	{
		wynik.re = Skl1.re / Skl2;
		wynik.im = Skl1.im / Skl2;
	}
	return wynik;
}
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
	LZespolona Licznik = Skl1 * Sprzezenie(Skl2);
	double Mianownik = Modul(Skl2)*Modul(Skl2);
	LZespolona wynik = Licznik / Mianownik;
	return wynik;
}


LZespolona Sprzezenie(LZespolona liczba)
{
	LZespolona wynik;
	wynik.re = liczba.re;
	wynik.im = -liczba.im;
	return wynik;
}
double Modul(LZespolona liczba)
{
	double wynik;
	wynik = liczba.re * liczba.re+liczba.im*liczba.im;
	wynik = sqrt(wynik);
	return wynik;
}



void Wyswietl(LZespolona liczba)
{
	if (liczba.im >= 0) {
		cout << "(" << liczba.re << "+" << liczba.im << "i" << ")";
	}
	else
	{
		cout << "(" << liczba.re << liczba.im << "i" << ")";
	}
}