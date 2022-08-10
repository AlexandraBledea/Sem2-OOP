//
// Created by Alexandra on 3/2/2021.
//

#pragma once
#include "service.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

Service* createService(Repository repo, UndoRepo UndoRedo)
{
    Service* service =(Service*)malloc(sizeof(Service));

    if(service == NULL)
        return NULL;
    service->repo = repo;
    service->undo_redo = UndoRedo;

    return service;
}

//void copy_repo_service(Service* service, UndoRedoData* UndoRedo)
//{
//    service->repo.count = UndoRedo->UndoRedoData[UndoRedo->CAction]->count;
//    service->repo.max_length = UndoRedo->UndoRedoData[UndoRedo->CAction]->max_length;
//    for(int i = 0; i < UndoRedo->UndoRedoData[UndoRedo->CAction]->count; i++)
//        service->repo.data[i] = UndoRedo->UndoRedoData[UndoRedo->CAction]->data[i];
//}

void copy_repo_service(Service* service, UndoRepo* UndoRedo)
{
    service->repo.array.count = UndoRedo->data[UndoRedo->current_position].array.count;
    service->repo.array.max_length = UndoRedo->data[UndoRedo->current_position].array.max_length;
    for(int i = 0; i < UndoRedo->data[UndoRedo->current_position].array.count; i++)
        service->repo.array.data[i] = UndoRedo->data[UndoRedo->current_position].array.data[i];
}

int compute_number_days_between_two_dates(Service* service, char date1[])
{
    int number_of_days = 0;
    char d1[11], m1[11], y1[11];
    int d_1, m_1, y_1, d_2, m_2, y_2;
    int d, m , y;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    d1[0] = date1[0];
    d1[1] = date1[1];
    m1[0] = date1[3];
    m1[1] = date1[4];
    y1[0] = date1[6];
    y1[1] = date1[7];
    y1[2] = date1[8];
    y1[3] = date1[9];


    d_2 = strtol(d1, NULL, 10);
    m_2 = strtol(m1, NULL, 10);
    y_2 = strtol(y1, NULL, 10);

    d_1 = tm.tm_mday;
    m_1 = tm.tm_mon + 1;
    y_1 = tm.tm_year + 1900;

    if(y_1 == y_2)
    {
        if(m_1 == m_2)
        {
            number_of_days = abs(d_2 - d_1);
            return number_of_days;
        }
        else if(m_1 != m_2)
        {
            m = abs(m_2 - m_1) - 1;
            m = m * 31;
            d = 31 - d_1;
            number_of_days = d_2 + m + d;
            return number_of_days;

        }
    }
    else
    {
        if(m_1 == m_2)
        {
            if (d_1 == d_2) {
                number_of_days = (y_2 - y_1) * 12 * 31;
                return number_of_days;
            } else if (d_1 < d_2) {
                number_of_days = (y_2 - y_1) * 31 * 12 + d_2 - d_1;
                return number_of_days;
            } else if (d_1 > d_2) {
                number_of_days = (y_2 - y_1) * 31 * 12 - (d_1 - d_2);
                return number_of_days;
            }
        }
        else
        {
            m = 12 - m_1;
            number_of_days = m * 31;
            m = m_2 - 1;
            number_of_days = number_of_days + m * 31;
            number_of_days = number_of_days + 31 - d_1 + d_2;
            number_of_days = number_of_days + (y_2 - y_1 - 1) * 31 * 12;
            return number_of_days;
        }

    }
}

void destroy_s(Service* service)
{
    if (service == NULL)
        return;

    free(service);
}

void add_product_s(Service* service, char name[], char type[], int quantity, char date[])
{
    add_product_r(&service->repo, name, type, quantity, date);
    add_repo_ur(&service->undo_redo, &service->repo);

}

int delete_product_s(Service* service, char name[], char type[])
{
    if(delete_product_r(&service->repo, name, type) == 0)
        return 0;
    else
    {
        add_repo_ur(&service->undo_redo, &service->repo);
        return 1;
    }
}

int update_products_expiration_date_s(Service* service, char name[], char type[], char date[])
{
    if(update_products_expiration_date_r(&service->repo, name, type, date) == 0)
        return 0;
    else
    {
        add_repo_ur(&service->undo_redo, &service->repo);
        return 1;
    }
}

void sort_function_quantity(Service* service, Repository* r)
{
    for(int i = 0; i < r->array.count-1; i++)
        for(int j = i + 1; j < r->array.count; j++)
            if(r->array.data[i].quantity > r->array.data[j].quantity)
            {
                Product aux = r->array.data[i];
                r->array.data[i] = r->array.data[j];
                r->array.data[j] = aux;
            }
}

void sort_function_name(Service* service, Repository* r)
{
    //char aux[100];
    for(int i = 0; i < r->array.count-1; i++)
        for(int j = i + 1; j < r->array.count; j++)
            if(strcmp(r->array.data[i].name, r->array.data[j].name) >0)
            {
//                strcpy(aux, r->data[i].name);
//                strcpy(r->data[i].name, r->data[j].name);
//                strcpy(r->data[j].name, aux);
                Product aux = r->array.data[i];
                r->array.data[i] = r->array.data[j];
                r->array.data[j] = aux;
            }
}


void search_elements_by_string_s(Service* service, char string[], Repository* repository, int criteria)
{
    search_elements_by_string_r(&service->repo, string, repository);
    if(criteria == 1)
        sort_function_quantity(service, repository);
    else
    if(criteria == 2)
        sort_function_name(service, repository);
}

int search_elements_by_category_s(Service* service, char string[], Repository* repository, int number_of_days)
{
    int ok = search_elements_by_category_r(&service->repo, string, repository);
    int i = 0;
    while(i < repository->array.count)
    {
        if(compute_number_days_between_two_dates(service, repository->array.data[i].date) != number_of_days)
            delete_product_r(repository, repository->array.data[i].name, repository->array.data[i].type);
        else
            i++;

    }

    if(repository->array.count == 0)
        return 0;
    else if(ok == 0)
        return 1;
    else
        return 2;
}

int update_products_quantity_s(Service* service, char name[], char type[], int quantity)
{

    if(update_products_quantity_r(&service->repo, name, type, quantity) == 0)
        return 0;
    else
    {
        add_repo_ur(&service->undo_redo, &service->repo);
        return 1;
    }
}
/*
Product search_elements_by_string_s_2(Service* service, char string[])
{
    Repository r;
    Repository rep;
    //*r.data = search_elements_by_string_r(&service->repo, string);
    //return *rep.data = sort_function(service, &r);
}
 */