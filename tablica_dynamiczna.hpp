#ifndef tablica_dynamiczna
#define tablica_dynamiczna
#include <iostream>

class TablicaDynamiczna { //tablica dynamiczna
private:
	int* data; //wskaźnik do tablicy
    int size;
	int capacity; //rozmiar tablicy
    void resize(); //zmiana rozmiaru tablicy
public:
    TablicaDynamiczna(int n); //konstruktor
    ~TablicaDynamiczna(); //dekonstruktor
    void addFirst(int value); //dodawanie na początek
    void addLast(int value); //dodawanie na koniec
    void addAtIndex(int index, int value); //dodawanie na wskazany indeks
    void deleteAtIndex(int index); //usuwanie z wskazanego indeksu
    void deleteFirst(); //usuwanie z początku
    void deleteLast(); //usuwanie z końca
    void show(); //pokazywanie tablicy
    void search(int value); //szukanie wartości
    void showAtIndex(int index); //pokazywanie elementu na wskazanym indeksie
};
#endif
