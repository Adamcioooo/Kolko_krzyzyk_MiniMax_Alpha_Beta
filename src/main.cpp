#include<bits/stdc++.h>
using namespace std;
#include "kolko_krzyzyk.hh"



int main(){

	int a = 0;									//Zmienan pomocnicza

	cout << endl;
	cout << "Podaj rozmiar planszy: ";			//Wyswietlanie komunikatu
	cin >> a;									//Wczytywanie rozmiaru planszy
	cout << endl;


	Gra** tablica = new (nothrow) Gra*[a];		//Dynamiczne alokowanie pamieci w tablicy 2 wymiarowej

	for(int i = 0; i < a; ++i){
	    tablica[i] = new Gra[a];				//Alokowanie pamieci dla 2 wymiaru
	}

	tablica[0][0].rozmiar= a;					//Zapisanie wartosci rozmiaru planszu

	wyzeruj(tablica);							//Wyzerowanie wszystkich pol tablicy

	graj(tablica);								//Rozpoczecie gry

    return 0;
}






















