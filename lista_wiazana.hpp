#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
struct Node { // struktura elementu
    int data; //wartość elementu
    Node* next; //wskaźnik do następnego elementu
    Node(int value);  //konstruktor 
};
class ListaWiazana // jednokierunkowa
{
private:
    Node* head; //wskaźnik do pierwszego elementu
    Node* tail; //wskaźnik do ostatniego elementu
	int count; //liczba elementów w liście
public:
   ListaWiazana(); //konstruktor
    ~ListaWiazana(); //dekonstruktor
    bool isEmpty(); //sprawdzenie czy lista jest pusta
    void addFirst(int value); //dodawanie na początek
    void addLast(int value); //dodawanie na koniec
    void addAtIndex(int index, int value); //dodawanie na wskazany indeks
    void deleteAtIndex(int index); //usuwanie z wskazanego indeksu
    void deleteFirst(); //usuwanie z początku
    void deleteLast(); //usuwanie z końca
    void show(); //pokazywanie tablicy
    void search(int value); //szukanie wartości
};
#endif
