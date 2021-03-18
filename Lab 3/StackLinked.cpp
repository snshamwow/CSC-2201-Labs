//StackLinked.h implementation by Sadeem Shamoun

#include <iostream>
#include "StackLinked.h"
#include <stdexcept>

using namespace std;

//Precondition: none
//Postcondition: makes top = null
//Input: maxNumber is passed as a parameter
//Output: makes top = null
template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
	top = nullptr;
}

//Precondition: none
//Postcondition: other stack copies into object
//Input: pass object "other" as a reference
//Output: outputs empty stack
template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	StackNode* current;
	StackNode* newNode;
	StackNode* last;
	
	if (top != nullptr)
	{
		top = nullptr;
	}

	if (other.top == nullptr)
	{
		top = nullptr;
	}

	else
	{
		current = other.top;
		top = new StackNode(NULL, nullptr);
		top->dataItem = current->dataItem;
		top->next = nullptr;
		last = top;
		current = current->next;

		while (current != nullptr)
		{
			newNode = new StackNode(NULL, nullptr);
			newNode->dataItem = current->dataItem;
			newNode->next = nullptr;
			last->next = newNode;
			last = newNode;
			current = current->next;
		}
	}
}

// Pre-condition: None
// Post-condition: assignment operator overloaded
// Input: pass "other" parameter
// Output: return "this" pointer
template<typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	if (this != &other)
	{
		StackLinked(other);
	}
	return *this;
}

//Precondition: none
//Postcondition: all nodes deleted
//Input:none
//Output: all memory deallocated
template<typename DataType>
StackLinked<DataType>::~StackLinked()
{
	StackNode* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

// Pre-condition: None
// Post-condition: added newData to list
// Input: pass newData by reference
// Output: a new node created with dataItem set to newData
template<typename DataType>
void StackLinked<DataType>::push(const DataType& newData) throw(logic_error)
{
	if (top == nullptr)
	{
		StackNode* newNode;
		newNode = new StackNode(NULL, nullptr);
		newNode->dataItem = newData;
		top = newNode;
	}
	else
	{
		StackNode* newNode;
		newNode = new StackNode(NULL, nullptr);
		newNode->dataItem = newData;
		newNode->next = top;
		top = newNode;
	}
}

// Pre-condition: top cannot be null
// Post-condition: top node deleted
// Input: none
// Output: specified node deleted
template<typename DataType>
DataType StackLinked<DataType>::pop() throw(logic_error)
{
	if (top == nullptr)
	{
		throw logic_error("Stack is empty");
	}
	else
	{
		StackNode* tmp;
		double returntop;
		returntop = top->dataItem;
		tmp = top;
		top = top->next;
		delete tmp;
		return returntop;
	}
}

// Pre-condition: none
// Post-condition: stack is emptied
// Input: none
// Output: the empty stack
template<typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

// Pre-condition: none
// Post-condition: check to see if stack is empty compeleted
// Input: none
// Output: true: stack is empty, false: stack is not empty
template<typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	return top == nullptr;
}

// Pre-condition: none
// Post-condition: none
// Input: none
// Output: false
template<typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

// Pre-condition: stack needs to exist
// Post-condition: outputs elemts if they exist
// Input: none
// Output: empty stack if empty, or data elements if not empty
template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != 0; temp = temp->next) {
			if (temp == top)
			{
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}
}

/// Pre-condition: None
/// Post-condition: lets us access private members
/// Input: passing in by reference the data and ptr
/// Output: instant variables of class StackNode have been initalized. 
template<typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}