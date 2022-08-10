//
// Created by Alexandra on 3/17/2021.
//
#include <cstdlib>
#include "domain.h"
#pragma once

template <class TElem>
class DynamicArray
{
private:
    TElem* elements;
    int length;
    int initial_capacity;
    int capacity;

    /// With this function we resize the dynamic array
    void Resize()
    {
        TElem* NewElements;
        this->capacity = this->capacity * 2;
        NewElements = new TElem[this->capacity];
        for(int i = 0; i < this->length; i++)
        {
            NewElements[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = NewElements;
    }

    /// With this function we clear the dynamic array
    void Clear()
    {
        this->length = 0;
        TElem* NewElements;
        this->capacity = this->initial_capacity;
        NewElements = new TElem[this->capacity];
        for(int i = 0; i < this->length; i++)
        {
            NewElements[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = NewElements;
    }

public:
/// Constructor
    DynamicArray(){
    }

    ///  With this function we initialize the dynamic array
    /// \param capacity
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        this->length = 0;
        this->elements = new TElem[capacity];
        this->initial_capacity = capacity;
    }

/// Destructor
    ~DynamicArray(){
        delete [] this->elements;
    }

/// With this function we add an element
/// \param element the element we are about to add
    void Add (const TElem &element)
    {
//        if(this->elements == nullptr)
//            return;
        if(this->length == this->capacity)
            Resize();
        this->elements[this->length++] = element;
    }

/// With this function we delete an element
/// \param position the position of the element we are about to delete
    void Delete(int position)
    {
        if (this->length == 1) // If array has only one element
            Clear(); // than we clear it, since it will be deleted
        else
        {
            // otherwise, shift array elements
            for(int i = position; i < this->length - 1; i++)
                this->elements[i] = this->elements[i+1];

            // decrease array size
            this->length--;
        }
    }

/// With this function we update an element
/// \param element the element we are about to update
/// \param position the position of the element
    void Update(const TElem &element, int position){
        this->elements[position] = element;
    }

///With this function we get the number of elements from the dynamic array
    int GetSize()
    {
        return this->length;
    }

/// With this function we get an exact element from the array
/// \param position the position of the element; we are about to get
/// \return it returns the element
    TElem& operator [] (int position){
        return this->elements[position];
    }
    DynamicArray& operator = (const DynamicArray &a){
        if(this == &a)
            return *this;

        if(a.capacity == 0)
            Clear();

        this->capacity = a.capacity/2;
        Resize();

        memcpy(this->elements, a.elements, sizeof(TElem)*a.capacity);
        return *this;

    }
};


//void* GetAll()
//    {
//        return this->elements;
//    }