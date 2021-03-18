#include <fstream>
#include <string>
#include <iostream>
#include "Text.h"
#include "Text.cpp"

using namespace std;

int main() {

    int iterator = 0;
    Text token;
    ifstream myFile;
    
    myFile.open("progsamp.dat");
    if (myFile.is_open()) 
    {

        while (!myFile.eof()) 
        {

            myFile >> token;

            if (myFile.eof()) 
            {
                break;
            }
           
            cout << iterator << ": [" << token << "]" << endl;

            iterator+= 1;

        }
        
        myFile.close();

    }
    else 
    {
        cout << "Error: Can't read file." << endl;
    }
}
