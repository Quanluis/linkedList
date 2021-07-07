// linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

class node {

    private: 

        string value;
        node  *next;
        friend class linkedList;

    public:

};


class linkedList {

    //variables 

    private: 

        node *head;

        void file();
        void intro();

    public: 

        void driver();

};

//methods

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

        const char file[] = "linkedText.txt";

        ifstream inputFile("linkedText.txt");

        if (inputFile.is_open()) {
  
            while (getline(inputFile, line)) {
                cout << line << endl;
                x++;
           }
            inputFile.close();

       }

    }

}

void linkedList::driver() {

    intro();
    file();

}

int main()
{ 

    linkedList run;
    run.driver();

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
