using namespace std;

#include <iostream>
#include "BSTree.cpp"
#include "config.h"

void print_help();

class TestData
{
public:

    void setKey(int newKey)
    {
        theKey = newKey;
    }  

    int getKey() const
    {
        return theKey;
    }    

private:

    int theKey;             
};

int main()
{
    BSTree<TestData, int> testTree;
    TestData testObject;              
    int inputKey;                 
    char userInput;                       

    print_help();

    do
    {
        testTree.revealTree();                     

        cout << endl << "Command: ";                  
        cin >> userInput;
        if (userInput == '+' || userInput == '?' ||
            userInput == '-' || userInput == '<')
            cin >> inputKey;

        switch (userInput)
        {
        case 'P': case 'p':
            print_help();
            break;

        case '+':                                 
            testObject.setKey(inputKey);
            cout << "Insert : key = " << testObject.getKey()
                << endl;
            testTree.insertHere(testObject);
            break;

        case '?':                                 
            if (testTree.retrieveHere(inputKey, testObject))
                cout << "Retrieved : getKey = "
                << testObject.getKey() << endl;
            else
                cout << "Not found" << endl;
            break;

        case '-':                                  
            if (testTree.removeThis(inputKey))
                cout << "Removed data item" << endl;
            else
                cout << "Not found" << endl;
            break;

        case 'K': case 'k':                      
            cout << "Keys:" << endl;
            testTree.keyWrite();
            break;

        case 'C': case 'c':                      
            cout << "Clear the tree" << endl;
            testTree.treeClearer();
            break;

        case 'E': case 'e':                    
            if (testTree.checkEmpty())
                cout << "Tree is empty" << endl;
            else
                cout << "Tree is NOT empty" << endl;
            break;

        case 'G': case 'g':                   
            cout << "Tree nodes count = " << testTree.getNumNodes() << endl;
            break;

        case 'H': case 'h':                  
            cout << "Tree height = " << testTree.getTreeHeight() << endl;
            break;
            
        case 'Q': case 'q':                  
            break;

        default:                              
            cout << "Inactive or invalid command. 'P' prints help." << endl;
        }
    } while (cin && (userInput != 'Q') && (userInput != 'q'));

    if (!cin) {
        cerr << "Error in console input. Exiting." << endl;
    }

    return 0;
}

void print_help() {
    cout << endl << "Commands:" << endl;
    cout << "  P    : [P]rint Help (displays this message)" << endl;
    cout << "  +key : Insert (or update) data item (use integers)" << endl;
    cout << "  ?key : Retrieve data item" << endl;
    cout << "  -key : Remove data item" << endl;
    cout << "  K    : Write keys in ascending order" << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  G    : Get count of nodes          "
#if LAB9_TEST1
        << "(Active   : "
#else
        << "(Active : "
#endif
        << "In-lab Exercise 2)" << endl;

    cout << "  H    : Height                      "
#if LAB9_TEST2
        << "(Active   : "
#else
        << "(Active : "
#endif
        << "In-lab Exercise 2)" << endl;

    cout << "  <key : Write keys that are < key   "
#if LAB9_TEST3
        << "(Active   : "
#else
        << "(Inactive : "
#endif
        << "In-lab Exercise 3)" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}

