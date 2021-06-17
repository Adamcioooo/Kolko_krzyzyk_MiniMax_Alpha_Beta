#include<bits/stdc++.h>
using namespace std;
#include "kolko_krzyzyk.hh"


char komputer = 'x', czlowiek = 'o';

//Funkcja sprzwdza czy zostaly jeszcze wolne pola na planszy
bool wolnePole(Gra **tablica){
    for (int i = 0; i < tablica[0][0].rozmiar; i++){			//Petla zwiekszajaca zakres rzedu
        for (int j = 0; j < tablica[0][0].rozmiar; j++){		//Petla zwiekszajaca zakres kolumn
            if (tablica[i][j].znak =='_'){						//Sprawdzenie czy na polu i, j jest znak '_'
            	return true;									//Jezeli jest znak zwraca true
            }
        }
    }
    return false;												//Jezeli nie ma zwraca false
}

//Funkcja przechowuje zasady gry
int zasady(Gra **tablica){

	int k = 0;															//Zmienna pomocnicza

	//Sprawdza czy s¹ te same znaki w rzêdach
    for (int row = 0; row < tablica[0][0].rozmiar; row++){				//Zwiekszenie zakresu rzedow
    	k = 0;
    	for(int col = 1; col < tablica[0][0].rozmiar; col++){			//Zwiekszenie zakresu kolum
    		if(tablica[row][col-1].znak != tablica[row][col].znak){		//Sprawdza czy 2 pola obok siebie w tym samym rzedzie maja ten sam znak
    			k++;													//Jezeli sa rozne to zwieksza zakres
    		}
    	}
        if (k == 0){													//Jezeli wszystkie pola w rzedzie maja ten sam znak
            if (tablica[row][0].znak==komputer)							//Jezeli dane pole ma znak "x"
                return +10;												//Zwraca +10
            else if (tablica[row][0].znak==czlowiek)					//Jezeli dane pole ma znak "o"
                return -10;												//Zwraca -10
        }
    }

    //Sprawdza czy s¹ te same znaki w kolumnach
    for (int col = 0; col < tablica[0][0].rozmiar; col++){				//Zwiekszenie zakresu kolum
    	k = 0;															//Wyzerowanie zmiennej
    	for(int row = 1; row < tablica[0][0].rozmiar; row++){			//Zwiekszenie zakresu rzedow
    	    if(tablica[row-1][col].znak != tablica[row][col].znak){		//Sprawdza czy 2 pola obok siebie w tym samym rzedzie maja ten sam znak
    	    	k++;													//Jezeli sa rozne to zwieksza zakres
    	    }
    	}
        if (k == 0){													//Jezeli wszystkie pola w rzedzie maja ten sam znak
            if (tablica[0][col].znak==komputer)							//Jezeli dane pole ma znak "x"
                return +10;												//Zwraca +10
            else if (tablica[0][col].znak==czlowiek)					//Jezeli dane pole ma znak "o"
                return -10;												//Zwraca -10
        }
    }

    //Sprawdza cz na diagonalnej s¹ te same znaki

    k = 0;																//Wyzerowanie zmiennej

    for (int l = 1; l < tablica[0][0].rozmiar; l++){					//Zwiekszenie zakresu zmiennej
    	if(tablica[l-1][l-1].znak != tablica[l][l].znak){				//Porownywanie znakow na diagonalnej
    		k++;														//Jezeli znaki sa rozne to zwieksza zakres
    	}
    }

    if (k == 0){														//Sprawdza czy wszystkie znaki na diagonalnej sa takie same
        if (tablica[0][0].znak==komputer)								//Jezeli dane pole ma znak "x"
            return +10;													//Zwraca +10
        else if (tablica[0][0].znak==czlowiek)							//Jezeli dane pole ma znak "o"
            return -10;													//Zwraca -10
    }

    k = 0;																//Wyzerowanie zmiennej
    //Sprawdza czy na drugiej diagonalnej sa te same znaki
    for (int l = 1; l < tablica[0][0].rozmiar; l++){					//Zwiekszenie zakresu zmiennej
    	if(tablica[tablica[0][0].rozmiar-l][l-1].znak != tablica[tablica[0][0].rozmiar-l-1][l].znak){	//Sprawdza czy wszystkie znaki na diagonalnej sa takie same
       		k++;														//Jezeli znaki sa rozne to zwieksza zakres
       	}
    }

    if (k == 0){														//Sprawdza czy wszystkie znaki na drugiej diagonalnej sa takie same
        if (tablica[tablica[0][0].rozmiar-1][0].znak==komputer)								//Jezeli dane pole ma znak "x"
            return +10;													//Zwraca +10
        else if (tablica[tablica[0][0].rozmiar-1][0].znak==czlowiek)							//Jezeli dane pole ma znak "o"
            return -10;													//Zwraca -10
    }

    return 0;															//Jezeli zaden z warunkow nie zostal spelniony zwraca 0
}

//Funkcja sprawdza mozliwe najlepsze i najgorsze ruchy podczas gry
int minimax(Gra **tablica, int depth, bool isMax, int alpha, int beta){

    int score = zasady(tablica);										//Sprawdza ktory z graczy moze wygrac

    if (score == 10)													//Jezeli wygrywa komputer
        return score;													//Zwraca 10

    if (score == -10)													//Jezeli wygrywa czlowiek
        return score;													//Zwraca -10

    if (wolnePole(tablica)==false)										//Sprawdza czy sa jeszcze wolne pola
        return 0;														//Zwraca 0

    if (isMax){															//Jezeli zostala uzyskana maksymalna wartosc
        int best = -1000;												//Podstawienie pod zmienna -1000

        for (int i = 0; i<tablica[0][0].rozmiar; i++){					//Zwiekszenie zakresu rzedow
            for (int j = 0; j<tablica[0][0].rozmiar; j++){				//Zwiekszenie zakresu kolumn
                if (tablica[i][j].znak=='_'){							//Sprawdz czy pole jets puste

                    tablica[i][j].znak = komputer;						//Podstawia pod dane pole 'x'

                    best = max( best,									//Porownuje wartosc best z wartoscia zwrocona przez minimax, zwraca wieksza
                        minimax(tablica, depth+1, !isMax, alpha, beta) );
                    alpha = max(alpha, best);							//Wykorzystanie ciec alpha-beta
                    tablica[i][j].znak = '_';							//Podstawia w danym polu '_'
                    if(beta <= alpha){
                    	break;
                    }
                }
            }
        }
        return best;													//Zwraca wartosc best
    }

    else
    {
        int best = 1000;												//Podstawienie pod zmienna 1000

        for (int i = 0; i < tablica[0][0].rozmiar; i++){				//Zwiekszenie zakresu rzedow
            for (int j = 0; j < tablica[0][0].rozmiar; j++){			//Zwiekszenie zakresu kolumn
                if (tablica[i][j].znak=='_'){							//Sprawdz czy pole jets puste

                    tablica[i][j].znak = czlowiek;						//Podstawia pod dane pole 'o'

                    best = min(best,
                           minimax(tablica, depth+1, !isMax, alpha, beta));			//Porownuje wartosc best z wartoscia zwrocona przez minimax, zwraca mniejsza
                    beta = min(beta, best);								//Wykorzystanie ciec alpha-beta
                    tablica[i][j].znak = '_';							//Podstawia w danym polu '_'
                    if(beta <= alpha){
                    	break;
                    }
                }
            }
        }
        return best;													//Zwraca wartosc best
    }
}
//Funkcja zwraca nalepszy ruch dla komputera
Gra najlepszyRuch(Gra **tablica, int alpha, int beta)
{
    int bestVal = -1000;								//Zmienna przechowujaca najlepsza wartosc
    Gra bestMove;
    bestMove.row = -1;									//Przypisanie -1 dla rzedu
    bestMove.col = -1;									//Przypisanie -1 dla kolumny

    for (int i = 0; i < tablica[0][0].rozmiar; i++)			//Zwiekszenie zakresu dla rzedow
    {
        for (int j = 0; j< tablica[0][0].rozmiar; j++)		//Zwiekszenie zakresu dla kolumn
        {
            if (tablica[i][j].znak=='_')					//Sprawdza czy dane pole jest puste
            {
                tablica[i][j].znak = komputer;				//Podstawia pod dane pole "x"

                int moveVal = minimax(tablica, 0, false, alpha, beta);	//Sprawdzenie najlepszego wyboru pozycji

                tablica[i][j].znak = '_';					//Wykasowanie wybranej pozycji podstawiajac "_"

                alpha = max(alpha, bestVal);				//Wykorzystanie ciec alpha-beta
                if(beta <= alpha){
                	break;
                }

                if (moveVal > bestVal)						//Sprawdzenie czy dana wartosc jest wieksza
                {
                    bestMove.row = i;						//Zapisanie wartosci rzedu
                    bestMove.col = j;						//Zapisanie wartosci kolumny
                    bestVal = moveVal;						//Przypisanie wartosci maksymalnej
                }
            }
        }
    }


    return bestMove;										//Zwraca wartosc maksymalna
}

//Funkcja wyswietla tablice w konsoli
void wyswietl(Gra **tablica){

	cout << "     ";										//Wyswietla odpowiednie cyfry dla pola

	for (int m = 0; m < tablica[0][0].rozmiar; m++){
		cout << m+1 << " ";
	}


	for (int i = 0; i < tablica[0][0].rozmiar; i++){		//Zwiekszenie zakresu rzedow
		cout << endl;										//Nowa linia
		cout << i+1 << "    ";								//Wyswietla odpowiednie cyfry dla pola

		for (int j = 0; j < tablica[0][0].rozmiar; j++){	//Zwiekszenie zakresu kolumn
			cout << tablica[i][j].znak << " ";				//Wyswietlenie danej pozycji

		}
	}
	cout << endl;
	cout << "***************" << endl;
	cout << endl << endl;

}
//Funkcja wykonuje ruch dla komputera
void ruchKomp(Gra **tablica, Gra bestMove){

	tablica[bestMove.row][bestMove.col].znak = komputer;		//Przypisanie wybranej pozycji "x"

}



//Funkcja wyzerowuje plansze
void wyzeruj(Gra ** tablica){

	for (int i = 0; i < tablica[0][0].rozmiar; i++){		//Petla zwieksza zakres rzedow
		for (int j = 0; j < tablica[0][0].rozmiar; j++){	//Petla zwieksza zakres kolumn
			tablica[i][j].znak = '_';						//Podstawienie pod pole i j "_"

		}
	}

}

//Fukcja wykonuje ruch gracza
void ruchGracz(Gra **tablica){

	int x = 0;													//Zmienna pomocnicza - kolumna
	int y = 0;													//Zmienna pomocnicza - rzad

	cout << "Podaj kolumne: ";									//Wyswietlenie komunikatu
	cin >> x;													//Wczytanie zmiennej
	cout << endl << "Podaj wiersz: ";							//Wyswietlenie komunikatu
	cin >> y;													//Wczytanie zmiennej

	if(x < 1 && x >= tablica[0][0].rozmiar){					//Sprawdza czy zostala wpisana odpowienia wartosc
		cout << "Wybrano zla wartosc!" << endl;					//Komunikat
		ruchGracz(tablica);										//Ponowne wybranie danej pozycji
	}

	if(tablica[y-1][x-1].znak != '_'){							//Sprawdza czy wybrane pole jest juz zajete
		cout << "Wybrane pozycja jest juz zajeta! " << endl;	//Wyswietla komunkat
		ruchGracz(tablica);										//Ponownie wybranie danej opcji
	}
	else{
		tablica[y-1][x-1].znak = czlowiek;						//Wstawienie w wybrane pole "o"

	}
}

//Funkcja sprzawdza ktory z graczy wygral
int wygrana(Gra **tablica){

	int k = 0;											//Zmienna pomocnicza

	if(!wolnePole(tablica)){							//Sprawdza czy wszystkie pola s¹ zajête
		cout << "****  REMIS  ****" << endl;			//Wyswietla komunikat o remisie
		return 0;
	}

	k = zasady(tablica);								//Przypisanie wartosci pod zmienna pomocnicza

	if(k > 0){											//Sprawdza czy zmienna pomocnicza jest wieksza od 0
		cout << "****  Wygrywa komputer  ****" << endl; //Wyswietla komunikat o wygranej komputera
		return 0;
	}
	else if(k < 0){										//Sprawdza czy zmienna pomocnicza jest mniejsza od 0
		cout << "****  Wygrywa gracz  ****" << endl;	//Wyswietla komunikat o wygranej cz³owieka
		return 0;
	}


    return 1;
}

//Funkcja uruchamia gre
void graj(Gra **tablica){

	int koniec = 1;								//Zmienna pomocnicza - flaga

	while(koniec){								//Petla dziala tak dlugo az koniec == 0

		Gra bestMove = najlepszyRuch(tablica,-1000,1000);	//Zwraca najlepszy ruch dla komputera

	   	ruchKomp(tablica, bestMove);			//Wykonuje ruch komputera
	   	wyswietl(tablica);						//Wyswietla tablice
    	koniec = wygrana(tablica);				//Sprawdza czy ktorys z graczy wygral

	    if(koniec){								//Sprawdzane jest czy gra nie zostala zakonczona
	   		ruchGracz(tablica);					//Wykonanie ruchu gracza - czlowieka
	   		koniec = wygrana(tablica);			//Sprawdzenie czy ktorys z graczy nie wygral
	   	}
   }
}

