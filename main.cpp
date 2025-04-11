#include <iostream>
#include "lista_dynamiczna.hpp"
#include "lista_wiazana.hpp"
using namespace std;

int main()
{
    ListaDynamiczna lista(2);
    lista.addLast(4000);
    lista.addLast(20);
    lista.addLast(30);
    lista.addLast(40);
    lista.show();
    lista.addFirst(5);
    lista.show();
    lista.addAtIndex(2, 15);
    lista.show();
    lista.deleteAtIndex(3);
    cout << "Zawartosc listy dynamicznej po usunieciu elementu z indeksu 3: ";
    lista.show();
    lista.deleteFirst();
    cout << "Zawartosc listy dynamicznej po usunieciu pierwszego elementu: ";
    lista.show();
    lista.deleteLast();
    cout << "Zawartosc listy dynamicznej po usunieciu ostatniego elementu: ";
    lista.show();
    lista.showAtIndex(1);
    lista.search(15);
    lista.search(100);
    return 0;
}