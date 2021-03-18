#include <iostream>
#include "Text.h"
#include "config.h"




Text::Text(const char* charSeq)
{
	bufferSize = (int)strlen(charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
}

Text::Text(const Text& other) : bufferSize(other.bufferSize)
{
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
}

void Text::operator= (const Text& other)
{
	if (this != &other)
	{
		int length = other.getLength();

		if (length >= bufferSize)
		{
			delete[] buffer;
		}

		bufferSize = length + 1;
		buffer = new char[bufferSize];
	}

	strcpy(buffer, other.buffer);
	bufferSize = other.bufferSize;
}

Text::~Text()
{
	delete[] buffer;
	bufferSize = 0;
}

int Text::getLength() const
{
	return bufferSize - 1;
}

char Text::operator[](int n) const
{
	if (bufferSize > n)
	{
		return buffer[n];
	}
	else
	{
		return 0;
	}
}

void Text::clear()
{
	delete[] buffer;
	bufferSize = 1;
	buffer = new char[bufferSize];
	buffer[0] = 0;
}

void Text::showStructure() const
{
	
	for (int i = 0; buffer[i] != 0; i++)
	{
		cout << buffer[i];
	}

	cout << endl;
}


Text Text::toUpper() const
{
	Text temp(buffer);
	for (int i = 0; i < bufferSize; i++)
	{
		temp.buffer[i] = toupper(char(buffer[i]));
	}
	return temp;
}

Text Text::toLower() const
{
	Text temp(buffer);
	for (int i = 0; i < temp.getLength(); i++) 
	{
		temp.buffer[i] = tolower(char(buffer[i]));
	}
	return temp;
}

bool Text::operator < (const Text& other) const
{
	return(strcmp(buffer, other.buffer) < 0);
}
bool Text::operator > (const Text& other) const
{
	return(strcmp(buffer, other.buffer) > 0);
}

bool Text::operator == (const Text& other) const
{
	return(strcmp(buffer, other.buffer) == 0);
}