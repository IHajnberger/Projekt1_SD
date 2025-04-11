#include "lista_dynamiczna.hpp"
#include <iostream>

using namespace std;
ListaDynamiczna::ListaDynamiczna(int n)
{
    data = new int[n];
    size = 0;
    capacity = n;
}
ListaDynamiczna::~ListaDynamiczna()
{
    delete[] data;  //zwalnianie pamiêci
}
void ListaDynamiczna::resize()
{
    capacity = capacity * 2;  //dwukrotne powiêkszenie rozmiaru tabliicy
}
void ListaDynamiczna::addFirst(int value)
{
    if (size == capacity)  //poszerzanie tablicy, gdy jest pe³na
    {
        resize();
    }
    for (int i = size; i > 0; i--) //przemieszczanie wszystkich elementów o jeden w prawo
    {
        data[i] = data[i - 1];
    }
    data[0] = value;  //ustawianie pierwszego elementu na now¹ wartoœæ
    size++;
}
void ListaDynamiczna::addLast(int value)
{
    if (size == capacity)
    {
        resize();
    }
    data[size] = value;  //dodawanie nowej wartoœci na koniec tablicy
    size++;
}
void ListaDynamiczna::addAtIndex(int index, int value)
{
    if (index < 0 || index > size)  //sprawdzenie czy index nie wykracza poza zakres tablicy
    {
        cout << "Indeks poza zakresem" << endl;
        return;
    }
    if (size == capacity)
    {
        resize();
    }
    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}
void ListaDynamiczna::deleteAtIndex(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Indeks poza zakresem" << endl;
        return;
    }
    for (int i = index; i < size - 1; i++)      //przemieszczanie wszystkich elementów o jeden w lewo
    {
        data[i] = data[i + 1];
    }
    size--;
}
void ListaDynamiczna::deleteFirst()
{
    if (size == 0)      //sprawdzenie czy tablica nie jest pusta
    {
        cout << "Brak elementow do usuniecia" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];      //przemieszczanie wszystkich elementów o jeden w lewo
    }
    size--;
}
void ListaDynamiczna::deleteLast()
{
    if (size == 0)
    {
        cout << "Brak elementow do usuniecia" << endl;
        return;
    }
    size--;
}
void ListaDynamiczna::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "]" << "." << data[i] << " ";
    }
    cout << endl;
}
void ListaDynamiczna::search(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            cout << "Znaleziono wartosc: " << value << " na indeksie: " << i << endl;
            return;
        }
    }
    cout << "Nie znaleziono wartosci: " << value << endl;
}
void ListaDynamiczna::showAtIndex(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Indeks poza zakresem" << endl;
        return;
    }
    cout << "Element na indeksie " << index << ": " << data[index] << endl;
}