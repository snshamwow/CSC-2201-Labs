#pragma once

#include <iostream>
#include <stdexcept>
#include "BSTree.h"
using namespace std;

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
{
    //precondition: none
    //postcondition:updated node 
    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;
}

template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree()
{
    //precondition: none
    //postcondition: initiliazes root of tree as null and makes empty tree
    root = (NULL);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree<DataType, KeyType>& other)
{
    //precondition: a tree needs to exist
    //postcondition: makes deep copy of tree
    root = (NULL); //root initialized to null
    *this = other; //tree assignment
}

template < typename DataType, class KeyType > BSTree< DataType, KeyType>::~BSTree()
{
    //precondition: none
    //postcondition: empty tree with root = 0
    treeClearer();
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::keyWrite() const
{
    //precondition: BST exists
    //postcondition: keys of nodes in BST are outputted from least to greatest
    keyWriteHelp(root);
    cout << endl;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getTreeHeight() const
{
    //precondition: BST exists
    //postcondition: BST exists
    return(treeHeightHelp(root));
}

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::treeHeightHelp(BSTreeNode* ptr) const
{
    //precondition: BST exists
    //postcondition: BST exists
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        if (treeHeightHelp(ptr->left) > treeHeightHelp(ptr->right))
        {
            return(1 + treeHeightHelp(ptr->left));
        }
        else
        {
            return(1 + treeHeightHelp(ptr->right));
        }
    }
}
template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::checkEmpty() const
{
    //precondition: BST exists
    //postcondition: checks if BST is empty
    return(root == (NULL));
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::revealTree() const
{
    //precondition: none
    //postcondition: none
    if (root == 0)
    {
        cout << "Empty tree" << endl;
    }
    else
    {
        cout << endl;
        treeRevealHelp(root, 1);
        cout << endl;
    }
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::treeRevealHelp(BSTreeNode* ptr,
    int level) const
{
    //precondition: none
    //postcondition: none
    int k;

    if (ptr != 0)
    {
        treeRevealHelp(ptr->right, level + 1);
        for (k = 0; k < level; k++)
            cout << "\t";
        cout << " " << ptr->dataItem.getKey();
        if ((ptr->left != 0) &&
            (ptr->right != 0))
            cout << "<";
        else if (ptr->right != 0)
            cout << "/";
        else if (ptr->left != 0)
            cout << "\\";
        cout << endl;
        treeRevealHelp(ptr->left, level + 1);
    }
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::treeCopyHelp(BSTreeNode*& destination, BSTreeNode* home)
{
    //precondition: two BST exist
    //postcondition: two bst exist that are copies of each other
    if (home != NULL)
    {
        destination = new BSTreeNode(home->dataItem, NULL, NULL);

        treeCopyHelp(destination->left, home->left);
        treeCopyHelp(destination->right, home->right);
    }
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::treeClearer()
{
    //precondition: none
    //postcondition: empty BSTree object
    treeClearerHelp(root);
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::treeClearerHelp(BSTreeNode*& ptr)
{
    //precondition: two BST exist
    //postcondition: two bst exist that are copies of each other
    if (ptr != NULL)
    {
        treeClearerHelp(ptr->left);
        treeClearerHelp(ptr->right);

        delete ptr;
        ptr = NULL;
    }
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insertHere(const DataType& newDataItem)
{
    //precondition: binary tree has to exist
    //postcondition: BST object is made with new node
    insertHereHelp(root, newDataItem);
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insertHereHelp(BSTreeNode*& ptr, const DataType& newDataItem)
{
    //precondition: BST exist
    //postcondition: BST exists with an inserted node.

    if (ptr == NULL)
    {
        ptr = new BSTreeNode(newDataItem, NULL, NULL);
    }
    else if (newDataItem.getKey() < ptr->dataItem.getKey())
    {
        insertHereHelp(ptr->left, newDataItem);
    }
    else if (newDataItem.getKey() > ptr->dataItem.getKey())
    {
        insertHereHelp(ptr->right, newDataItem);
    }
    else
    {
        ptr->dataItem = newDataItem;
    }
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieveHere(const KeyType& searchKey, DataType& searchDataItem) const
{
    //precondition: BST exists
    //postcondition: object thats passed is equal to the search item
    return(retrieveHereHelp(root, searchKey, searchDataItem));
}

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrieveHereHelp(BSTreeNode* ptr, const KeyType& searchKey, DataType& searchDataItem) const
{
    //precondition: BST and node exist
    //postcondition: two bst exist that are copies of each other
    if (ptr == NULL)
    {
        return false;
    }
    else if (searchKey < ptr->dataItem.getKey())
    {
        return(retrieveHereHelp(ptr->left, searchKey, searchDataItem));
    }
    else if (searchKey > ptr->dataItem.getKey())
    {
        return(retrieveHereHelp(ptr->right, searchKey, searchDataItem));
    }
    else
    {
        searchDataItem = ptr->dataItem;
        return true;
    }
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::removeThis(const KeyType& deleteKey)
{
    //precondition: BST exists
    //postcondition: removes node inputted by user
    return(removeThisHelp(root, deleteKey));
}

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removeThisHelp(BSTreeNode*& ptr, const KeyType& deleteKey)
{
    //precondition: BST exists
    //postcondition: BST exists without specified node.
    BSTreeNode* temp;
    if (ptr == NULL)
    {
        return false;
    }
    else if (deleteKey < ptr->dataItem.getKey())
    {
        return(removeThisHelp(ptr->left, deleteKey));
    }
    else if (deleteKey > ptr->dataItem.getKey())
    {
        return(removeThisHelp(ptr->right, deleteKey));
    }
    else
    {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            ptr = NULL;
            return true;
        }
        else if (ptr->left != NULL && ptr->right == NULL)
        {
            temp = ptr;
            ptr = ptr->left;
            delete temp;
            return true;
        }
        else if (ptr->left == NULL && ptr->right != NULL)
        {
            temp = ptr;
            ptr = ptr->right;
            delete temp;
            return true;
        }
        else
        {
            temp = ptr->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            ptr->dataItem = temp->dataItem;
            removeThisHelp(ptr->left, temp->dataItem.getKey());
        }
    }
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::keyWriteHelp(BSTreeNode* ptr) const
{
    //precondition: BST exists
    //postcondition: nodes are written from least to greatest
    if (ptr != NULL)
    {
        keyWriteHelp(ptr->left);
        cout << (ptr->dataItem).getKey() << ' ';
        keyWriteHelp(ptr->right);
    }
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getNumNodes() const
{
    //precondition: BST exists
    //postcondition: BST exists
    return(treeCountHelp(root));
}

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::treeCountHelp(BSTreeNode* ptr) const
{
    //precondition: BST exists
    //postcondition: BST exists
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return(1 + treeCountHelp(ptr->left) + treeCountHelp(ptr->right));
    }
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>::operator=(const BSTree<DataType, KeyType>& other)
{
    //precondition: there needs to be two binary trees
    //postcondition: BSTree object on left side of assignemtn operator is now the same as 
    //the right side.
    if (root != NULL)
    {
        treeClearer();
    }

    else
    {
        treeCopyHelp(root, other.root);
        return *this;
    }
}


