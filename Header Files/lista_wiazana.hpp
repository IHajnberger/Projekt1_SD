#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
struct Node {
    int data; //wartość
    Node* next; //wskaźnik do następnego elementu
    Node(int value);  //konstruktor
};
class ListaWiazana
{
private:
    Node* head; //wskaźnik do pierwszego elementu
    Node* tail; //wskaźnik do ostatniego elementu
public:
    ListaWiazana(); //konstruktor
    ~ListaWiazana(); //dekonstruktor
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
