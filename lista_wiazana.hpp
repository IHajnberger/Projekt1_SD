#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
struct Node {
    int data; //wartoœæ
    Node* next; //wskaŸnik do nastêpnego elementu
    Node(int value);  //konstruktor
};
class ListaWiazana
{
private:
    Node* head; //wskaŸnik do pierwszego elementu
    Node* tail; //wskaŸnik do ostatniego elementu
public:
    ListaWiazana(); //konstruktor
    ~ListaWiazana(); //dekonstruktor
    void addFirst(int value); //dodawanie na pocz¹tek
    void addLast(int value); //dodawanie na koniec
    void addAtIndex(int index, int value); //dodawanie na wskazany indeks
    void deleteAtIndex(int index); //usuwanie z wskazanego indeksu
    void deleteFirst(); //usuwanie z pocz¹tku
    void deleteLast(); //usuwanie z koñca
    void show(); //pokazywanie tablicy
    void search(int value); //szukanie wartoœci
};
#endif