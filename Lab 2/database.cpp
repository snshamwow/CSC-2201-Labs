#pragma once

#include <iostream>
#include <fstream>
#include "BSTree.cpp"

using namespace std;

const int nameLen = 11;                       
const long bytesPerRecord = 38;   

struct AccountRecord
{
    int userAccID;               
    char firstN[nameLen];         
    char lastN[nameLen];
    double money;               
};

struct IndexEntry
{
    int userAccID;            
    long lineNumber;            

    int getKey() const
    {
        return userAccID;
    }  
};

int main()
{
    ifstream inFile("accounts.dat");   
    AccountRecord accountData{};             
    BSTree<IndexEntry, int> place;           
    IndexEntry entry;                    
    int userSearchID;                     
    long lineNumber = 0;                    

    string tempVar;
    inFile >> entry.userAccID;
    while (inFile.is_open() && inFile.good())
    {
        inFile >> tempVar >> tempVar >> tempVar;
        entry.lineNumber = lineNumber;
        lineNumber = lineNumber + 1;
        place.insertHere(entry);
        inFile >> entry.userAccID;
    }

    cout << endl << "Account ID number: " << endl;
    place.keyWrite();

    inFile.clear();
    inFile.close();
    inFile.open("accounts.dat");

    cout << endl << "Enter account ID number: ";
    while (cin >> userSearchID)
    {
        if (place.retrieveHere(userSearchID, entry))
        {
            for (int i = -1; i < entry.lineNumber; i++)
            {
                inFile >> accountData.userAccID;
                inFile >> accountData.firstN >> accountData.lastN;
                inFile >> accountData.money;
            }
            cout << (entry.lineNumber + 1) << " : ";
            cout << accountData.userAccID << " ";
            cout << accountData.firstN << " ";
            cout << accountData.lastN << " ";
            cout << accountData.money;
        }
        else
        {
            cout << "No account with that account number has been found. Please try again. ";
        }
        inFile.clear();
        inFile.close();
        inFile.open("accounts.dat");
        cout << endl << "Enter account ID number: ";
    }
    return (0);
}
