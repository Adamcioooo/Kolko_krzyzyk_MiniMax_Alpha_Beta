#ifndef KOLKO_KRZYZYK_HH
#define KOLKO_KRZYZYK_HH
#include<bits/stdc++.h>
#include <iostream>
using namespace std;



//Struktura Gra przechowujaca pola row - rzad, col - kolumna, rozmiar planszy oraz odpowiedni znak "o", "_" lub "x"
struct Gra
{
    int row;
    int col;
    int rozmiar;
    char znak;
};



//Funkcja sprzwdza czy zostaly jeszcze wolne pola na planszy
bool wolnePole(Gra **tablica);

//Funkcja przechowuje zasady gry
int zasady(Gra **tablica);

//Funkcja sprawdza mozliwe najlepsze i najgorsze ruchy podczas gry
int minimax(Gra **tablica, int depth, bool isMax,int alpha, int beta);

//Funkcja zwraca nalepszy ruch dla komputera
Gra najlepszyRuch(Gra **tablica, int alpha, int beta);

//Funkcja wyswietla tablice w konsoli
void wyswietl(Gra **tablica);

//Funkcja wykonuje ruch dla komputera
void ruchKomp(Gra **tablica, Gra bestMove);

//Funkcja wyzerowuje plansze
void wyzeruj(Gra ** tablica);

//Fukcja wykonuje ruch gracza
void ruchGracz(Gra **tablica);

//Funkcja sprzawdza ktory z graczy wygral
int wygrana(Gra **tablica);

//Funkcja uruchamia gre
void graj(Gra **tablica);


































#endif
