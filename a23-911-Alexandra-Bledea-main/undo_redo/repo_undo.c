//
// Created by Alexandra on 3/12/2021.
//

#include "repo_undo.h"


//
// Created by Alexandra on 3/10/2021.
//
#include "repository.h"
#include "repo_undo.h"
#include <stdio.h>
#include <stdlib.h>

UndoRepo* createUndoRepo(int capacity, Repository* repo)
{
    UndoRepo* U = (UndoRepo*)malloc(sizeof(UndoRepo));
    //make sure that the space was allocated
    if (U==NULL)
        return NULL;
    U->count = 0;
    U->max_length = capacity;
    U->current_position = 0;
    U->total_operations = 0;

    //allocate space for the elements
    U->data = (Repository* )malloc(capacity * sizeof(Repository));
    if (U->data == NULL)
        return NULL;

    U->data[U->current_position] = duplicate_repo(repo);
    //U->data[U->current_position] = *repo;

    //getData(repo, &U->data[U->current_position]);

//    U->data[U->current_position].count = repo->count;
//    U->data[U->current_position].max_length = repo->max_length;
//    U->data[U->current_position] = *repo;

    return U;
}

void destroy_ur(UndoRepo* U)
{

    if (U == NULL)
        return;

    //free the space allocated for the repositories
//    for(int j = 0; j< U->count; j++)
//        for(int i = 0; i < U->data[j].count; i++)
//            free(&U->data[i]);

    for(int i = 0; i <= U->count; i++)
        free(U->data[i].array.data);

    free(U->data);
    U->data = NULL;

    //free the space allocated for the dynamic array
    free(U);
}

void resize_ur(UndoRepo* U)
{
    U->data = (Repository* )(realloc(U, sizeof(Repository)* U->max_length * 2));
    U->max_length = U->max_length * 2;
}

void add_repo_ur(UndoRepo* U, Repository* repo)
{
    if ( U == NULL)
        return;
    if(U->data == NULL)
        return;

    //resize the array, if necessary
    if(U->max_length == U->current_position)
        resize_ur(U);

    U->current_position++;
    U->count++;
    U->total_operations = U->current_position;
//    U->data[U->current_position].count = repo->count;
//    U->data[U->current_position].max_length = repo->max_length;
    //U->data[U->current_position] = *repo;
    U->data[U->current_position] = duplicate_repo(repo);
    //getData(repo, &U->data[U->current_position]);

}

int RedoOperation(UndoRepo* UndoRedo)
{
    if(UndoRedo->current_position == UndoRedo->total_operations)
        return 0;

    UndoRedo->current_position++;
    return 1;

}

int UndoOperation(UndoRepo * UndoRedo)
{
    if(UndoRedo->current_position == 0)
        return 0;

    UndoRedo->current_position--;
    return 1;
}

//void delete_repo_ur(UndoRepo* U)
//{
//    for(int i = U->count-1; i < U->count; i++)
//        U->data[i] = U->data[i+1];
//    U->count--;
//}
