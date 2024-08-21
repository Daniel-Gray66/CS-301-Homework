#ifndef DOUBLY_LINKEDLIST_HPP
#define DOUBLY_LINKEDLIST_HPP
#include "List.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class DoublyLinkedList : public List<T> {
    protected:
        // represents an element in the linked list
        struct Node {
            T value;
            Node* next;
            Node* prev;
            // node constructor
            Node(T v = T(), Node* n = nullptr, Node* m = nullptr)
            : value(v), next(n), prev(m)  { }
        };

        // Using two extra nodes as indicators at both the front and the back 
        //of the lsit
        //dont carry any actual information
        Node* Trailer;
        Node* Header;



    public:
        // default constructor
        DoublyLinkedList();

        // destructor
        virtual ~DoublyLinkedList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() override;

        // return the current length of the list
        virtual int getLength() const override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const DoublyLinkedList<U>&);

};

#endif

// This was supposed to be a tpp file but I couldnt get it to owrk on visual studio well enoough
// Hence why this is such a big file


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()  {
    Header = new Node;
    Trailer = new Node;
    Header->next = Trailer;
    Trailer->prev = Header;

}


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
    delete Header;
    delete Trailer;
}

template <typename T>
void DoublyLinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    Node* t = Trailer->prev;
    Trailer->prev = n;
    n->next = Trailer;
    t->next = n;
    n->prev = t;

    this->length++;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    
    Node* Current = Trailer->prev;
    while (Current!= Header)
    {
        Node* temp = Current;
        Current = Current->prev;
        delete temp;
    }

    Header->next = Trailer;
    Trailer->prev = Header;
    this->length = 0;
}

template <typename T>
int DoublyLinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return Header->next == Trailer;
}


template <typename T>
ostream& operator<<(ostream& outStream, const DoublyLinkedList<T>& myObj) {
    ofstream myfile;
    myfile.open("Out.txt");
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
       
        //checking if the file even opened
        if (!myfile.is_open())
        {
            throw "File did not open";
        }

        //The weird syntax that I found worked Idk y 
        typename DoublyLinkedList<T>::Node* curr = myObj.Header->next;
        while (curr != myObj.Trailer) {
            // this is printing to terminal
            outStream << setfill('0') << setw(3) <<  curr->value;
            cout << ",";

            //printing to file
            myfile << setfill('0') << setw(3) << curr->value;
            myfile << ",";
           
            curr = curr->next;
        }
        myfile << endl;
        outStream << endl;
    }
    myfile.close();
    return outStream;
}