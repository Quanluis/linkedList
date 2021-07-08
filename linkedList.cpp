// linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

// Node for list Item

class node {

    private: 

        string value;
        node  *next;
        friend class linkedList;

    public:
        
        node(string, node *);

};

class nodeReversed {
    
    private:

        string valueReveresed;
        node *nextReversed;



    public: 
     //   nodeReveresed(string, nodeReversed *);


};

// Linked list itself

class linkedList {

    //variables 

    private: 

        node *head;

        void file();
        void intro();
        void print();
        

    public: 

        void add(string);
        void driver();
        linkedList();
        ~linkedList();

};

// linkedList constructor

linkedList::linkedList() {
    head = NULL;
}



//methods

node::node(string line, node* p) { 
    value = line;
    next = p; 
}

void linkedList::intro() {

    cout << "This program reads a file with characters and put it into a linked object." << endl;

}

void linkedList::file() {

    ifstream inputFile;

  //   inputFile.open("linkedText.txt");

    if (!inputFile) {
        cout << "File not found try again" << endl;

        exit(0);
    }
    else {
        cout << "File has been found" << endl;

        string line;
        
        int x = 0;

        // const char file[] = "linkedText.txt";

        ifstream inputFile("linkedText.txt");

        if (inputFile.is_open()) {
  
            while (getline(inputFile, line)) {
              //  cout << line << endl;
              //  x++;

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

void linkedList::print() {

    node *p = head;

    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }

    cout << endl;

}

void linkedList::driver() {

    intro();
    file();
    print();

}

// linkedList Destructor

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
