// linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

// Node for list ItemS

class node {

    private: 

        string value;
        node  *next;
        friend class linkedList;

    public:
        
        node(string, node *);

};

// Linked list itself

class linkedList {

    //variables 

    private: 

        node *head;

        void file();
        void intro();
        void print();
        void printReveresed();
        void add(string);
        
    public: 

        void driver();
        linkedList();
        ~linkedList();

};

// linkedList constructor

linkedList::linkedList() {
    head = NULL;
}

// METHODS 

// node decleration

node::node(string line, node* p) { 
    value = line;
    next = p; 
}

// Basic program intro function

void linkedList::intro() {

    cout << "This program reads a file with characters and puts it into a linked object." << endl;

}

// File intake function

void linkedList::file() {

    ifstream inputFile;

    if (!inputFile) {
        cout << "File not found try again" << endl;

        exit(0);
    }
    else {
        cout << "File has been found" << endl;

        string line;
        
        int x = 0;

        ifstream inputFile("linkedText.txt");

        if (inputFile.is_open()) {
  
            while (getline(inputFile, line)) {

              add(line);
                
           }
            inputFile.close();

       }

    }

}

// adds a given value to the list

void linkedList::add(string line) {

    head = new node(line, head);

}

// Prints the first linkedList

void linkedList::print() {

    node *p = head;

    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }

    cout << endl;

}

// Prints the reveresed linkedList

void linkedList::printReveresed() {

    node *prev = NULL;
    node *next = NULL;

    node *p = head;

    int i = 0;

    while (head != NULL) {
        
        prev = p->next;
        p->next = prev;
        next = p;
        p = prev;
        
        for (int x = 9; x >= 0; x--) {

            cout << head->value[x];
        }

        head = head->next;
    }

    cout << endl;

    head = prev;

}

// Program Driver

void linkedList::driver() {

    intro();
    file();
    print();
    printReveresed();

}

// Deconstructor

linkedList::~linkedList() {

    while (head != 0) {

        node *p = head;
        head = head->next;
        delete p;
    }

}

int main()
{ 

    linkedList run;

    run.driver();

    system("pause");

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
