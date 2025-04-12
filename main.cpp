#include <iostream>
#include <chrono>
#include <fstream> 
#include "tablica_dynamiczna.hpp"
#include "lista_wiazana.hpp"

using namespace std;
using namespace std::chrono;

int main()
{
    ofstream outputFile("wyniki.txt"); // Tworzenie pliku do zapisu wyników
    if (!outputFile.is_open())
    {
        cerr << "Nie można otworzyć pliku do zapisu!" << endl;
        return 1;
    }

    long long time = 0;
    int size = 100;  // liczba elementów w liście
    TablicaDynamiczna Dynamic(size);   // inicjalizacja listy dynamicznej
    ListaWiazana Linked;             // inicjalizacja listy wiązanej
    int rep = 100;  // liczba powtórzeń

    // Zapełnianie listy dynamicznej do zamierzanej wielkości
    for (int i = 0; i < size; i++) 
    { 
        Dynamic.addLast(i); 
        Linked.addLast(i);
    }

    // addFirst - ListaDynamiczna
    time = 0;
    cout << "Rozpoczynam test addFirst (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.addFirst(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Dynamiczna addFirst: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test addFirst (Dynamiczna)" << endl;

    // addFirst - ListaWiazana
    time = 0;
    cout << "Rozpoczynam test addFirst (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.addFirst(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Wiazana addFirst: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test addFirst (Wiazana)" << endl;

    // addLast - ListaDynamiczna
    time = 0;
    cout << "Rozpoczynam test addLast (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.addLast(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Dynamiczna addLast: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test addLast (Dynamiczna)" << endl;

    // addLast - ListaWiazana
    time = 0;
    cout << "Rozpoczynam test addLast (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.addLast(400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Wiazana addLast: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test addLast (Wiazana)" << endl;

    // addAtIndex - ListaDynamiczna
    time = 0;
    cout << "Rozpoczynam test addAtIndex (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.addAtIndex(size / 2, 400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Dynamiczna addAtIndex: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test addAtIndex (Dynamiczna)" << endl;

    // addAtIndex - ListaWiazana
    time = 0;
    cout << "Rozpoczynam test addAtIndex (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.addAtIndex(size / 2, 400);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Wiazana addAtIndex: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test addAtIndex (Wiazana)" << endl;

    // deleteFirst - ListaDynamiczna
    time = 0;
    cout << "Rozpoczynam test deleteFirst (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.deleteFirst();
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Dynamiczna deleteFirst: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test deleteFirst (Dynamiczna)" << endl;

    // deleteFirst - ListaWiazana
    time = 0;
    cout << "Rozpoczynam test deleteFirst (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.deleteFirst();
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Wiazana deleteFirst: " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test deleteFirst (Wiazana)" << endl;

    // search - ListaDynamiczna
    time = 0;
    cout << "Rozpoczynam test search dla liczby 90 (Dynamiczna)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Dynamic.search(90);
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Dynamiczna search (90): " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test search dla liczby 90 (Dynamiczna)" << endl;

    // search - ListaWiazana
    time = 0;
    cout << "Rozpoczynam test search dla liczby 90 (Wiazana)" << endl;
    for (int i = 0; i < rep; i++) 
    {
        auto start = high_resolution_clock::now();
        Linked.search(90); // Poszukiwana wartość
        auto stop = high_resolution_clock::now();
        time += duration_cast<nanoseconds>(stop - start).count();
    }
    outputFile << "Wiazana search (90): " << time / rep << " nanosekund" << endl;
    cout << "Zakonczono test search dla liczby 90 (Wiazana)" << endl;
    return 0;
    outputFile.close(); // Zamknięcie plikua
}