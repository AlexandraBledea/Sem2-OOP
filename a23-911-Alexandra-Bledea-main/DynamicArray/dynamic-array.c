//
// Created by Alexandra on 3/15/2021.
//

#include "dynamic-array.h"
#include <stdlib.h>

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    // make sure that the space was allocated
    if (da == NULL)
        return NULL;

    da->max_length = capacity;
    da->count = 0;

    // allocate space for the elements
    da->data = (TElem*)malloc(capacity * sizeof(TElem));
    if (da->data == NULL)
        return NULL;

    return da;
}

void destroy(DynamicArray* array)
{
    if (array == NULL)
        return;

    // free the space allocated for the planets
    free(array->data);
    array->data = NULL;

    // free the space allocated for the dynamic array
    free(array);
}

void resize(DynamicArray* array)
{
    array->data = (TElem* )(realloc(array, sizeof(TElem) * array->max_length * 2));
    array->max_length = array->max_length * 2;
}

void delete_TElem(DynamicArray* array, int position)
{
    for (int i = position; i <= array->count - 1; i++)
        array->data[i] = array->data[i + 1];

    array->count--;
}

void add_TElem(DynamicArray* array, TElem TElem)
{
    if (array == NULL)
        return;
    if(array->data == NULL)
        return;

    // resize the array, if necessary
    if(array->max_length == array->count)
        resize(array);
    array->data[array->count] = TElem;
    array->count++;

}

void update_TElem(DynamicArray* array, TElem TElem, int position)
{
    array->data[position] = TElem;
}