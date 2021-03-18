#pragma once

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >  
class BSTree                                    
{
protected:

    class BSTreeNode           
    {
    public:
        BSTreeNode(const DataType& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr);

        DataType dataItem;         
        BSTreeNode* left;   
        BSTreeNode* right;   
        DataType getKey()
        {
            return dataItem;
        }
    };
public:
    BSTree();                         
    BSTree(const BSTree<DataType, KeyType>& other);   
    BSTree& operator= (const BSTree<DataType, KeyType>& other);
    ~BSTree();

    void insertHere(const DataType& newDataItem);  
    bool retrieveHere(const KeyType& searchKey, DataType& searchDataItem) const;

    bool removeThis(const KeyType& deleteKey);            
    void keyWrite() const;                     
    void treeClearer();                              

    bool checkEmpty() const;                     

    void revealTree() const;

    int getTreeHeight() const;          
    int getNumNodes() const;			  

    void treeRevealHelp(BSTreeNode* ptr, int level) const;

    void treeCopyHelp(BSTreeNode*& destination, BSTreeNode* home);

    void treeClearerHelp(BSTreeNode*& ptr);

    void insertHereHelp(BSTreeNode*& ptr, const DataType& newDataItem);

    bool retrieveHereHelp(BSTreeNode* ptr, const KeyType& searchKey, DataType& searchDataItem) const;

    bool removeThisHelp(BSTreeNode*& ptr, const KeyType& deleteKey);

    void keyWriteHelp(BSTreeNode* ptr) const;

    int treeCountHelp(BSTreeNode* ptr) const;

    int treeHeightHelp(BSTreeNode* ptr) const;


    BSTreeNode* root;
};

#endif	// define BSTREE_H


