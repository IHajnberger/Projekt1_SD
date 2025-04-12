#include <iostream>
#include "lista_wiazana.hpp"
using namespace std;

Node::Node(int value) // konstruktor węzła
{
	data = value; // ustawienie wartości elementu
	next = nullptr; // ustawienie wskaźnika do następnego elementu na nullptr
}
ListaWiazana::ListaWiazana() // konstruktor listy
{
    head = nullptr;  //inicjalizacja wskaźnika do pierwszego elementu
    tail = nullptr;     //inicjalizacja wskaźnika do ostatniego elementu
    count = 0;          //pusta lista 
}
ListaWiazana::~ListaWiazana()  // destruktor listy
{
    Node* current = head;   //wskaźnik do aktualnego elementu
    Node* nextNode;     //wskaźnik do następnego elementu
    while (current != nullptr) 
    {
		nextNode = current->next; // zapamiętanie następnego elementu
		delete current;  // usunięcie aktualnego elementu
		current = nextNode;  // przejście do następnego elementu
    }
	head = nullptr;     // ustawienie wskaźnika do pierwszego elementu na nullptr   
	tail = nullptr;     // ustawienie wskaźnika do ostatniego elementu na nullptr
}
bool ListaWiazana::isEmpty() // sprawdzenie czy lista jest pusta
{
	return head == nullptr; // sprawdzenie czy wskaźnik do pierwszego elementu jest równy nullptr
}

void ListaWiazana::addFirst(int value) // dodawanie na początek
{
    if (isEmpty())
    {
		head = new Node(value); //jeśli lista jest pusta, dodajemy nowy element jako pierwszy
        tail = head;
    }
    else
    {
		Node* newNode = new Node(value); //tworzymy nowy element
		newNode->next = head; // ustawiamy wskaźnik nowego elementu na aktualny pierwszy element
		head = newNode; // przesuwamy wskaźnik do pierwszego elementu na nowy element
    }  
	count++; // zwiększamy licznik elementów
}
void ListaWiazana::addLast(int value) // dodawanie na koniec
{
    if(isEmpty())
    {
        head = new Node(value);     //jeśli lista jest pusta, dodajemy nowy element jako pierwszy
        tail = head; 
    }
    else
    {
		Node* newNode = new Node(value); //tworzymy nowy element
        tail->next = newNode; 
        tail = newNode; 
    }
    count ++;
}
void ListaWiazana::addAtIndex(int index, int value) // dodawanie na wskazany indeks
{
        if (index < 0 || index > count) // sprawdzenie czy indeks nie wykracza poza zakres listy
        {
            cout << "Indeks poza zakresem" << endl;
            return;
        }
		if (index == 0) // jeśli dodajemy na początek
        {
            addFirst(value);     //dodajemy na początek
            return;
        }
		if (index == count) // jeśli dodajemy na koniec
        {
            addLast(value);     //dodajemy na koniec
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head; 
		for (int i = 0; i < index - 1; i++) // przechodzimy do elementu przed wskazanym indeksem
        {
            current = current->next;
        }
		newNode->next = current->next; // ustawiamy wskaźnik nowego elementu na następny element
		current->next = newNode; // ustawiamy wskaźnik aktualnego elementu na nowy element
        count++; 
}
void ListaWiazana::deleteAtIndex(int index) // usuwanie z wskazanego indeksu
{
	if (index < 0 || index >= count) // sprawdzenie czy indeks nie wykracza poza zakres listy
    {
        cout << "Indeks poza zakresem" << endl;
        return;
    }
    if(index == 0) //jeśli usuwamy pierwszy element
    {
        deleteFirst(); 
        return;
    }
	if (index == count - 1) //jeśli usuwamy ostatni element
    {
        deleteLast(); 
        return;
    }
    Node* current = head;
	for (int i = 0; i < index - 1; i++) // przechodzimy do elementu przed wskazanym indeksem
    {
        current = current->next;
    }
    Node* Delete = current->next; 
    current->next = Delete->next; 
    delete Delete; 
}
void ListaWiazana::deleteFirst() // usuwanie z początku
{
	if (isEmpty()) // sprawdzenie czy lista jest pusta
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    Node* current = head; // wskaźnik do elementu do usunięcia
    head = head->next; // przesunięcie wskaźnika do pierwszego elementu na następny
    delete current; 
    count--;
    if (head == nullptr)    //jeśli pusta, tail ustawiamy na nullptr
    { 
        tail = nullptr;
    }
}
void ListaWiazana::deleteLast() // usuwanie z końca
{
    if (isEmpty()) 
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    if (head == tail) // jeśli jest tylko jeden element w liście
     { 
        delete head;
        head = nullptr;
        tail = nullptr;
    } 
    else 
    {
        Node* current = head;
        while (current->next != tail) // przechodzimy do przedostatniego elementu by go zapamiętać
         { 
            current = current->next;
        }
        delete tail; 
        tail = current; 
        tail->next = nullptr; 
    }
    count--;
}
void ListaWiazana::show() // pokazywanie listy
{
    if (isEmpty()) 
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    Node* current = head; 
    int index = 0; 
	while (current != nullptr)  // dopóki nie osiągniemy końca listy
    { 
        cout << "[" << index << "] " << current->data << " "; 
        current = current->next;
        index++;
    }
    cout << endl; 
}
void ListaWiazana::search(int value) // szukanie wartości
{
    if (isEmpty()) 
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    Node* current = head;
    int index = 0; 
    while (current != nullptr) // dopóki nie osiągniemy końca listy
     { 
        if (current->data == value)    //sprawdzamy czy aktualny element to szukana wartość
        {
            cout << "Znaleziono element o wartości " << value << " na indeksie " << index << "." << endl;
            return;
        }
        current = current->next; 
        index++;
    }
    cout << "Nie znaleziono elementu o wartości " << value << "." << endl;
}
