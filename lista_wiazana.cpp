#include <iostream>
#include "lista_wiazana.hpp"
using namespace std;

Node::Node(int value)
{
    data = value;
    next = nullptr;
}
ListaWiazana::ListaWiazana()
{
    head = nullptr;  //inicjalizacja wskaźnika do pierwszego elementu
    tail = nullptr;     //inicjalizacja wskaźnika do ostatniego elementu
    count = 0;
}
ListaWiazana::~ListaWiazana()
{
    Node* current = head;   //wskaźnik do aktualnego elementu
    Node* nextNode;     //wskaźnik do następnego elementu
    while (current != nullptr) 
    {
        nextNode = current->next; 
        delete current; 
        current = nextNode; 
    }
    head = nullptr; 
    tail = nullptr; 
}
bool ListaWiazana::isEmpty()
{
    return head == nullptr; 
}

void ListaWiazana::addFirst(int value)
{
    if (isEmpty())
    {
        head = new Node(value);
        tail = head;
    }
    else
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }  
    count ++;
}
void ListaWiazana::addLast(int value)
{
    if(isEmpty())
    {
        head = new Node(value);     //jeśli lista jest pusta, dodajemy nowy element jako pierwszy
        tail = head; 
    }
    else
    {
        Node* newNode = new Node(value);
        tail->next = newNode; 
        tail = newNode; 
    }
    count ++;
}
void ListaWiazana::addAtIndex(int index, int value)
{
        if (index < 0 || index > count) 
        {
            cout << "Indeks poza zakresem" << endl;
            return;
        }
        if (index == 0) 
        {
            addFirst(value);     //dodajemy na początek
            return;
        }
        if (index == count) 
        {
            addLast(value);     //dodajemy na koniec
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head; 
        for (int i = 0; i < index - 1; i++) 
        {
            current = current->next;
        }
        newNode->next = current->next; 
        current->next = newNode;
        count++; 
}
void ListaWiazana::deleteAtIndex(int index)
{
    if(index < 0 || index >= count) 
    {
        cout << "Indeks poza zakresem" << endl;
        return;
    }
    if(index == 0) //jeśli usuwamy pierwszy element
    {
        deleteFirst(); 
        return;
    }
    if(index == count - 1) 
    {
        deleteLast(); 
        return;
    }
    Node* current = head;
    for(int i = 0; i < index - 1; i++) 
    {
        current = current->next;
    }
    Node* Delete = current->next; 
    current->next = Delete->next; 
    delete Delete; 
}
void ListaWiazana::deleteFirst()
{
    if (isEmpty()) 
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
void ListaWiazana::deleteLast()
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
void ListaWiazana::show()
{
    if (isEmpty()) 
    {
        cout << "Lista jest pusta." << endl;
        return;
    }
    Node* current = head; 
    int index = 0; 
    while (current != nullptr)  
    { 
        cout << "[" << index << "] " << current->data << " "; 
        current = current->next;
        index++;
    }
    cout << endl; 
}
void ListaWiazana::search(int value)
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
            //cout << "Znaleziono element o wartosci " << value << " na indeksie " << index << "." << endl;
            return;
        }
        current = current->next; 
        index++;
    }
   // cout << "Nie znaleziono elementu o wartości " << value << "." << endl;
}
