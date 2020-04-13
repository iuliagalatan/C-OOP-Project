#pragma once
#include <iostream>
#include "Domain.h"


template <class TElems>
class DynamicVector
{
private:
	int position;
	int size;
	int capacity;
	TElems* elements;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& );
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& );

	// Adds an element to the current DynamicVector.
	void add(const TElems& );

	int getSize() const;

	// returns the element on a given position
	// the position must be a valid one
	TElems get(int position) const;

	int getCapacity() const;
	void setSize(int value) { size = value; }
	void setElement(int position, TElems newelement);
	void deleteElement(int position);

private:
	
	void ShrinktoFit();
	void IncreaseStorage();
	void resize();  // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
};

template <class TElems>
DynamicVector<TElems>::DynamicVector(const DynamicVector& dynamicvector)
{
	this->size = dynamicvector.size;
	this->capacity = dynamicvector.capacity;
	this->elements = new TElems[this->capacity];
	this->position = 0;
	for (int i = 0; i <= this->size; ++i)
		elements[i] = dynamicvector.elements[i];
}

template <class TElems>
DynamicVector<TElems>::DynamicVector(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new TElems[this->capacity];
	this->position = 0;
}

template <class TElems>
DynamicVector<TElems>::~DynamicVector()
{
	delete[] elements;
}

template <class TElems>
DynamicVector<TElems>& DynamicVector<TElems>::operator=(const DynamicVector<TElems>& dynamicvector)
{
	if (this == &dynamicvector)
		return *this;

	this->size = dynamicvector.size;
	this->capacity = dynamicvector.capacity;

	delete[] this->elements;
	this->elements = new TElems[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = dynamicvector.elements[i];

	return *this;
}

template <class TElems>
void DynamicVector<TElems>::add(const TElems& element)
{
	if (this->size == this->capacity)
		this->IncreaseStorage();
	this->elements[this->size] = element;
	this->size++;
}

template <class TElems>
int DynamicVector<TElems>::getSize() const
{
	return size;
}

template <class TElems>
TElems DynamicVector<TElems>::get(int position) const 
{
	if (position < size)
		return elements[position];
}

template <class TElems>
void DynamicVector<TElems>::ShrinktoFit()
{
	capacity /= 2;
	resize();
}

template <class TElems>
void DynamicVector<TElems>::IncreaseStorage()
{
	capacity *= 2;
	resize();
}

template <class TElems>
void DynamicVector<TElems>::resize()
{
	TElems* newarray = new TElems[capacity];

	for (int i = 0; i <= size; ++i)
		newarray[i] = elements[i];

	delete[] elements;
	elements = newarray;
}

template <class TElems>
void DynamicVector<TElems>::setElement(int position, TElems newelement)
{
	elements[position] = newelement;
}

template <class TElems>
int DynamicVector<TElems>::getCapacity() const
{
	return this->capacity;
}

template <class TElems>
void DynamicVector<TElems>::deleteElement(int position)
{
	if (this->size < this->capacity / 2)
		this->ShrinktoFit();
	for (int i = position + 1; i < this->getSize(); i++)
		elements[i - 1] = elements[i];
	this->setSize(this->getSize() - 1);
}