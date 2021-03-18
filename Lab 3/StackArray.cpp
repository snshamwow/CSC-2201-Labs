//StackArray.h implementation by Sadeem Shamoun

#include <iostream>
#include "StackArray.h"
#include "Stack.h"
#include <stdexcept>

using namespace std;

// Pre-condition: None
// Post-condition: max array size is stored in maxNumber and empty stack created
// Input: maxnumber, maximum the stack can hold
// Output: initializes top as 0 and makes maxNumber a constant
template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{
	maxSize = maxNumber;
	top = -1;
	dataItems = new DataType[maxSize];
}

// Pre-condition: other object must exist
// Post-condition: new object is equal to other object
// Input: other as a parameter
// Output: new object is equal to other object
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	maxSize = other.maxSize;
	top = other.top;
	dataItems = new DataType[maxSize];

	for (int i = 0; i < top; i++)
	{
		dataItems[i] = other.dataItems[i];
	}
}

// Pre-condition: objects cannot be equal to eachother
// Post-condition: objects now have the same private member values
// Input: other as reference (constant)
// Output: return "this" object 
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
	if (this != &other)
	{
		delete[] dataItems;
		maxSize = other.maxSize;
		top = other.top;

		dataItems = new DataType[maxSize];

		for (int i = 0; i <= top; i++)
		{
			dataItems[i] = other.dataItems[i];
		}
	}
	return *this;
}


// Pre-condition: none
// Post-condition: deletes memory stored in stack
// Input: none
// Output: empty stack
template <typename DataType>
StackArray<DataType>::~StackArray()
{
	delete[] dataItems;
}

// Pre-condition: stack isn't full
// Post-condition: number added to stack
// Input: add user input (newDataItem) into stack 
// Output: none
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (!isFull())
	{
		top++;
		dataItems[top] = newDataItem;

	}
	else
		throw logic_error("Stack is full.");
}


// Pre-condition: stack isn't empty 
// Post-condition: removes top item in stack
// Input: none
// Output: return the top item removed
template <typename DataType>
DataType StackArray<DataType>::pop()throw (logic_error)
{
	if (!isEmpty())
	{
		DataType copy;
		copy = dataItems[top];
		top--;
		return copy;
	}
	else throw logic_error("Stack is empty nothing to remove");
}

// Pre-condition: none
// Post-condition: stack is empty 
// Input: none
// Output: none
template <typename DataType>
void StackArray<DataType>::clear()
{
	if (!isEmpty())
	{
		for (int i = 0; i <= top; i++)
		{
			dataItems[i] = NULL;
		}
		top = -1;
	}
}

// Pre-condition: none
// Post-condition: checks if stack is empty
// Input: none
// Output: return true if stack is empty, false if not
template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	return top == -1;
}

// Pre-condition: none
// Post-condition: tells you if stack is full or otherwise
// Input: none
// Output: true if top = maxsize 
template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	if (top == 7)
	{
		return true;
	}
	else
		return false;
}

template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
	if (isEmpty()) {
		cout << "Empty stack." << endl;
	}
	else {
		int j;
		cout << "Top = " << top << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j <= top; j++)
		{
			if (j == top)
			{
				cout << '[' << dataItems[j] << ']' << "\t";
			}
			else
			{
				cout << dataItems[j] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}