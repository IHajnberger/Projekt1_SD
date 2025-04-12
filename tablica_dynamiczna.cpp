#include "tablica_dynamiczna.hpp"
#include <iostream>

using namespace std;
TablicaDynamiczna::TablicaDynamiczna(int n)
{
    data = new int[n];
    size = 0;
    capacity = n;
}
TablicaDynamiczna::~TablicaDynamiczna()
{
    delete[] data;  //zwalnianie pamięci
}
void TablicaDynamiczna::resize() {
    int new_capacity = capacity * 2;
    int* new_data = new int[new_capacity];
    std::copy(data, data + size, new_data); // Kopiowanie elementów
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
void TablicaDynamiczna::addFirst(int value)
{
    if (size == capacity)  //poszerzanie tablicy, gdy jest pełna
    {
        resize();
    }
    for (int i = size; i > 0; i--) //przemieszczanie wszystkich elementów o jeden w prawo
    {
        data[i] = data[i - 1];
    }
    data[0] = value;  //ustawianie pierwszego elementu na nową wartość
    size++;
}
void TablicaDynamiczna::addLast(int value)
{
    if (size == capacity)
    {
        resize();
    }
    data[size] = value;  //dodawanie nowej wartości na koniec tablicy
    size++;
}
void TablicaDynamiczna::addAtIndex(int index, int value)
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
void TablicaDynamiczna::deleteAtIndex(int index)
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
void TablicaDynamiczna::deleteFirst()
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
void TablicaDynamiczna::deleteLast()
{
    if (size == 0)
    {
        cout << "Brak elementow do usuniecia" << endl;
        return;
    }
    size--;
}
void TablicaDynamiczna::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "]" << "." << data[i] << " ";
    }
    cout << endl;
}
void TablicaDynamiczna::search(int value)
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
void TablicaDynamiczna::showAtIndex(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Indeks poza zakresem" << endl;
        return;
    }
    cout << "Element na indeksie " << index << ": " << data[index] << endl;
}
