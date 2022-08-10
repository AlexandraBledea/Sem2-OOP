//
// Created by Alexandra on 3/2/2021.
//
#pragma once
#include "../repository/repository.h"
#include "../domain/domain.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dynamic-array.h"

Repository* createRepo(DynamicArray arr)
{
    Repository* R = (Repository*)malloc(sizeof(Repository));
    //make sure that the space was allocated
    if (R == NULL)
        return NULL;

    R->array = arr;

    return R;
}

void copy_repo(Repository* repo, Repository new_repo)
{
    for(int i = 0; i<repo->array.count; i++)
        assign_values(&new_repo.array.data[i], repo->array.data[i]);
}

Repository duplicate_repo(Repository* repo)
{
    Repository new_repo;
    new_repo.array.max_length = repo->array.max_length;
    new_repo.array.count = repo->array.count;

    new_repo.array.data = (Product*)malloc(new_repo.array.max_length * sizeof(Product));

    copy_repo(repo, new_repo);
    return new_repo;

}S

void init_repo(Repository* R)
{
    add_product_r(R, "Banana", "fruit", 100, "01.04.2022");
    add_product_r(R, "Apple", "fruit", 50, "01.04.2021");
    add_product_r(R, "Chicken", "meat", 10, "16.03.2022");
    add_product_r(R, "Pork", "meat", 40, "16.03.2023");
    add_product_r(R, "Chocolate", "sweets", 70, "06.09.2021");
    add_product_r(R, "Cake", "sweets", 124, "18.03.2021");
    add_product_r(R, "Milk", "dairy", 3, "16.06.2021");
    add_product_r(R, "Yogurt", "dairy", 5, "16.06.2021");
    add_product_r(R, "Cherry", "fruit", 150, "01.04.2022");
    add_product_r(R, "Cupcake", "sweets", 70, "18.03.2021");
}

void destroy_r(Repository* R)
{
    if (R == NULL)
        return;

    free(R);

}

void search_elements_by_string_r(Repository* repo, char string[], Repository* repository)
{
    string[strlen(string) - 1] = '\0';
    if(strcmp(string, "") == 0)
    {
        for (int i = 0; i < repo->array.count; i++)
            add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
                          repo->array.data[i].date);
    }
    else
    {
        for(int i = 0; i< repo->array.count; i++)
            if(strstr(repo->array.data[i].name, string) != NULL)
                add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
                              repo->array.data[i].date);
    }

}

int search_elements_by_category_r(Repository* repo, char string[], Repository* repository)
{   int count = 0;
    for (int i = 0; i < repo->array.count; i++)
        if (strstr(repo->array.data[i].type, string) != NULL)
        {
            count++;
            add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
                          repo->array.data[i].date);

        }

    if (count == 0)
    {
        for (int i = 0; i < repo->array.count; i++)
            add_product_r(repository, repo->array.data[i].name, repo->array.data[i].type, repo->array.data[i].quantity,
                          repo->array.data[i].date);
    }

    if(count != 0)
        return 1;
    else
        return 0;
}

int check_existence_product(Repository* repo, char name[], char type[])
{
    for(int i = 0; i < repo->array.count; i++)
        if((strcmp(repo->array.data[i].name, name) == 0) && (strcmp(repo->array.data[i].type, type)==0))
            return i;
    return -1;
}

int delete_product_r(Repository* repo, char name[], char type[])
{
    int position;
    position = check_existence_product(repo, name, type);
    if(position == -1)
        return 0;
    else
    {
        delete_TElem(&repo->array, position);
        return 1;
    }
}

int update_products_quantity_r(Repository* repo, char name[], char type[], int quantity)
{
    int position;
    position = check_existence_product(repo, name, type);
    if(position == -1)
        return 0;
    else
    {
        Product p = createProduct(name, type, quantity, getDate(&repo->array.data[position]));
        //repo->array.data[position].quantity = quantity;
        update_TElem(&repo->array, p, position);
        return 1;
    }
}


void add_product_r(Repository* repo, char name[], char type[], int quantity, char date[])
{
    int position;
    position = check_existence_product(repo, name, type);
    if(position == -1)
    {
        Product product;
        product = createProduct(name, type, quantity, date);
        add_TElem(&repo->array, product);
    }
    else
    {
        repo->array.data[position].quantity = repo->array.data[position].quantity + quantity;
    }

}

int update_products_expiration_date_r(Repository* repo, char name[], char type[], char date[])
{
    int position;
    position = check_existence_product(repo, name, type);
    if(position == -1)
        return 0;
    else
    {
        Product p = createProduct(name, type, getQuantity(&repo->array.data[position]), date);
        //strcpy(repo->array.data[position].date, date);
        update_TElem(&repo->array, p, position);
        return 1;
    }
}

int getCount(Repository* R)
{
    return R->array.count;
}

/*


void test_getData()
{
    Repository* repo = createRepo(100);
    init_repo(repo);
    Repository new_repo;
    new_repo = getData(repo);
    for(int i = 0; i < new_repo.count; i++)
    {
        assert(strcmp(new_repo.data[i].name, repo->data[i].name) == 0);
        assert(strcmp(new_repo.data[i].type, repo->data[i].type) == 0);
        assert(new_repo.data[i].quantity == repo->data[i].quantity);
        assert(strcmp(new_repo.data[i].date, repo->data[i].date) == 0);
    }
    destroy_r(repo);
    destroy_r_2(&new_repo);
}

void test_getData()
{
    Repository* repo = createRepo(100);
    init_repo(repo);
    Repository* new_repo = createRepo(100);
    getData(repo, new_repo);
    for(int i = 0; i < new_repo->count; i++)
    {
        assert(strcmp(new_repo->data[i].name, repo->data[i].name) == 0);
        assert(strcmp(new_repo->data[i].type, repo->data[i].type) == 0);
        assert(new_repo->data[i].quantity == repo->data[i].quantity);
        assert(strcmp(new_repo->data[i].date, repo->data[i].date) == 0);
    }
    destroy_r(repo);
    destroy_r(new_repo);
}

 void test_resize()
{
    Repository* repo = createRepo(10);
    init_repo(repo);
    resize(repo);
    assert(repo->max_length == 20);
    //destroy_r(repo);

    free(repo->data);
    free(repo);
}

 void getData(Repository* R, Repository* repo)
{
    //Repository repo;
    repo->count = R->count;
    repo->max_length = R->max_length;
    repo->data = (Product*)malloc(repo->count*sizeof(Product));

    for(int i = 0; i < repo->count; i++)
        repo->data[i] = R->data[i];
}

 void un_init_repo(Repository* r)
{
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
}

void destroy_r_2(Repository* R)
{
    if (R == NULL)
        return;

    //free the space allocated for the products

    R->data = NULL;
    free(R);
}

void add_product_r(Repository* repo, char name[], char type[], int quantity, char date[])
{
    int position;
    position = check_existence_product(repo, name, type);
    if(position == -1)
    {
        Product product;
        product = createProduct(name, type, quantity, date);
        repo->data[repo->count] = product;
        repo->count++;
    }
    else
    {
        repo->data[position].quantity = repo->data[position].quantity + quantity;
    }

}


 Product search_elements_by_string_r_2(Repository* repo, char string[])
{
    Repository* r;
    if(strcmp(string, ""))
        return *repo->data;
    else
    {
        for(int i = 0; i <= repo->count; i++)
            if(strstr(repo->data[i].name, string) != NULL)
                add_product_r(repo, repo->data[i].name, repo->data[i].type, repo->data[i].quantity, repo->data[i].date);
        return*r->data;
    }
}

Repository copy_of_the_repo(Repository* repo)
{
    Repository* copy_of_the_repo, tempA, tempB, temp;

    if(repo!=NULL){
        copy_of_the_repo = (Repository*)malloc(sizeof(Repository));
        copy_of_the_repo->data = repo->data;
        b->next = NULL;

        tempA = a->next;
        tempB = b;

        while(tempA!=NULL){
            temp = (list)malloc(sizeof(cell));
            temp->data = tempA->data;
            temp->next = NULL;

            tempB->next = temp;
            tempB = temp;

            tempA = tempA->next;
        }
    }

    return b;
}
*/

