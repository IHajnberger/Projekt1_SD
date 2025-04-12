#include <iostream>
#include "tablica_dynamiczna.hpp"
#include "lista_wiazana.hpp"
using namespace std;

int main()
{
    TablicaDynamiczna tablicaD(2);
    tablicaD.addLast(4000);
    tablicaD.addLast(20);
    tablicaD.addLast(30);
    tablicaD.addLast(40);
    tablicaD.show();
    tablicaD.addFirst(5);
    tablicaD.show();
    tablicaD.addAtIndex(2, 15);
    tablicaD.show();
    tablicaD.deleteAtIndex(3);
    cout << "Zawartosc listy dynamicznej po usunieciu elementu z indeksu 3: ";
    tablicaD.show();
    tablicaD.deleteFirst();
    cout << "Zawartosc listy dynamicznej po usunieciu pierwszego elementu: ";
    tablicaD.show();
    tablicaD.deleteLast();
    cout << "Zawartosc listy dynamicznej po usunieciu ostatniego elementu: ";
    tablicaD.show();
    tablicaD.showAtIndex(1);
    tablicaD.search(15);
    tablicaD.search(100);
    return 0;
}
