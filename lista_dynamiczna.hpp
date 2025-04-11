#ifndef lista_dynamiczna
#define lista_dynamiczna
#include <iostream>

class ListaDynamiczna {
private:
    int* data;
    int size;
    int capacity;
    void resize(); //zmiana rozmiaru tablicy
public:
    ListaDynamiczna(int n); //konstruktor
    ~ListaDynamiczna(); //dekonstruktor
    void addFirst(int value); //dodawanie na pocz�tek
    void addLast(int value); //dodawanie na koniec
    void addAtIndex(int index, int value); //dodawanie na wskazany indeks
    void deleteAtIndex(int index); //usuwanie z wskazanego indeksu
    void deleteFirst(); //usuwanie z pocz�tku
    void deleteLast(); //usuwanie z ko�ca
    void show(); //pokazywanie tablicy
    void search(int value); //szukanie warto�ci
    void showAtIndex(int index); //pokazywanie elementu na wskazanym indeksie
};
#endif