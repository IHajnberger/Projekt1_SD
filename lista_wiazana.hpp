#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
struct Node {
    int data; //warto��
    Node* next; //wska�nik do nast�pnego elementu
    Node(int value);  //konstruktor
};
class ListaWiazana
{
private:
    Node* head; //wska�nik do pierwszego elementu
    Node* tail; //wska�nik do ostatniego elementu
public:
    ListaWiazana(); //konstruktor
    ~ListaWiazana(); //dekonstruktor
    void addFirst(int value); //dodawanie na pocz�tek
    void addLast(int value); //dodawanie na koniec
    void addAtIndex(int index, int value); //dodawanie na wskazany indeks
    void deleteAtIndex(int index); //usuwanie z wskazanego indeksu
    void deleteFirst(); //usuwanie z pocz�tku
    void deleteLast(); //usuwanie z ko�ca
    void show(); //pokazywanie tablicy
    void search(int value); //szukanie warto�ci
};
#endif