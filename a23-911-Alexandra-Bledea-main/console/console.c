//
// Created by Alexandra on 3/2/2021.
//
#pragma once
#include "../service/service.h"
#include "../console/console.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../validation/validation.h"
#include <stdlib.h>
#include "dynamic-array.h"

Console* createConsole(Service service)
{
    Console* console = (Console*)malloc(sizeof(Console));

    if(console == NULL)
        return NULL;

    console->service = service;

    return console;
}

void destroy_ui(Console* console)
{
    if(console == NULL)
        return;

    free(console);
}

void display_products_ui(Console* console)
{
    for(int i = 0; i < console->service.repo.array.count; i++)
        printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", console->service.repo.array.data[i].name,
               console->service.repo.array.data[i].type, console->service.repo.array.data[i].quantity,
               console->service.repo.array.data[i].date);

}

void add_product_ui(Console* console)
{
    char name[100] = "";
    char type[100] = "";
    char quantity[100] = "";
    int new_quantity;
    char date[100] = "";
    char empty[100] = "";
    printf("Type in the name of the product: ");
    gets_s(empty, sizeof(empty));
    gets_s(name, sizeof(name));
    printf("Type in the type of the product: ");
    gets_s(type, sizeof(type));
    printf("Type in the quantity of the product: ");
    gets_s(quantity, sizeof(quantity));
    printf("Type in the expiration date: ");
    gets_s(date, sizeof(date));
    if(validate_product_name(name) !=0 && validate_expiration_date(date) != 0 && validate_product_quantity(quantity)
       && validate_product_type(type))
    {
        new_quantity = validate_product_quantity(quantity);
        add_product_s(&console->service, name, type, new_quantity, date);
    }
    else
        printf("Invalid parameters!");
}

void delete_product_ui(Console* console)
{
    char name[100] = "";
    char type[100] = "";
    char empty[100] = "";
    printf("Type in the name of the product: ");
    gets_s(empty, sizeof(empty));
    gets_s(name, sizeof(name));
    printf("Type in the type of the product: ");
    gets_s(type, sizeof(type));
    if(validate_product_name(name) != 0 && validate_product_type(type) != 0)
    {
        if (delete_product_s(&console->service, name, type) == 0)
            printf("There is no product with the given name and type!");
        else
            printf("The product was deleted successfully!");
    }
    else
        printf("Invalid parameters!");
}

void update_products_expiration_date_ui(Console* console)
{
    char name[100] = "";
    char type[100] = "";
    char date[100] = "";
    char empty[100] = "";
    printf("Type in the name of the product: ");
    gets_s(empty, sizeof(empty));
    gets_s(name, sizeof(name));
    printf("Type in the type of the product: ");
    gets_s(type, sizeof(type));
    printf("Type in the expiration date of the product: ");
    gets_s(date, sizeof(date));
    if(validate_product_name(name) != 0 && validate_product_type(type) != 0 && validate_expiration_date(date) != 0)
    {
        if(update_products_expiration_date_s(&console->service, name, type, date) == 1)
            printf("The product's expiration date was updated successfully!");
        else
            printf("The given product doesn't exist!");
    }
    else
        printf("Invalid parameters!");

}

void update_products_quantity_ui(Console* console)
{
    int new_quantity;
    char name[100] = "";
    char type[100] = "";
    char quantity[100] = "";
    char empty[100] = "";
    printf("Type in the name of the product: ");
    gets_s(empty, sizeof(empty));
    gets_s(name, sizeof(name));
    printf("Type in the type of the product: ");
    gets_s(type, sizeof(type));
    printf("Type in the quantity of the product: ");
    gets_s(quantity, 100);
    if(validate_product_name(name) != 0 && validate_product_type(type) != 0 && validate_product_quantity(quantity) != 0)
    {
        new_quantity = validate_product_quantity(quantity);
        if(update_products_quantity_s(&console->service, name, type, new_quantity) == 1)
            printf("The product's quantity was updated successfully!");
        else
            printf("The given product doesn't exist!");
    }
    else
        printf("Invalid parameters!");
}

void search_elements_by_string_ui(Console* console)
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* R = createRepo(*DA);
    char empty[100] = "";
    char string[100] = "";
    int criteria;

    printf("Type in the string after which you want to search the products: ");
    gets_s(empty, sizeof(empty));
    fgets(string, sizeof(string), stdin);
    printf("Type 1 if you want to sort by quantity or type 2 if you want to sort by name: ");
    scanf("%d", &criteria);
    if(validate_criteria(criteria) == 0)
        printf("Invalid parameters!");
    else
    {
        search_elements_by_string_s(&console->service, string, R, criteria);
        for (int i = 0; i < R->array.count; i++)
            printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", R->array.data[i].name,
                   R->array.data[i].type, R->array.data[i].quantity, R->array.data[i].date);
    }
    destroy_r(R);
    destroy(DA);
}

void display_products_by_category(Console* console)
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* R = createRepo(*DA);
    char empty[100] = "";
    char type[100] = "";
    int number_of_days;
    printf("Type in the category by which you want to display the products: ");
    gets_s(empty, sizeof(empty));
    gets_s(type, sizeof(type));
    if(validate_product_type(type) != 0)
    {
        printf("Type in the number of days: ");
        scanf("%d", &number_of_days);
        if(search_elements_by_category_s(&console->service, type, R, number_of_days) == 0)
            printf("There are no products which check the conditions for display!");
        else if(search_elements_by_category_s(&console->service, type, R, number_of_days) == 1)
        {
            printf("There were no products available from that category, so we took all of them into consideration!");
            for(int i = 0; i < R->array.count; i++)
                printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", R->array.data[i].name,
                       R->array.data[i].type, R->array.data[i].quantity, R->array.data[i].date);

        }
        else
            for(int i = 0; i < R->array.count; i++)
                printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", R->array.data[i].name,
                       R->array.data[i].type, R->array.data[i].quantity, R->array.data[i].date);
    }
    else
        printf("The given category doesn't exist! Try again!");
    destroy_r(R);
    destroy(DA);
}

void undo_ui(Console* console)
{
    if(UndoOperation(&console->service.undo_redo) == 0)
        printf("There is no undo operation available!");
    else
        copy_repo_service(&console->service, &console->service.undo_redo);
}

void redo_ui(Console* console)
{
    if(RedoOperation(&console->service.undo_redo) == 0)
        printf("There is no redo operation available!");
    else
        copy_repo_service(&console->service, &console->service.undo_redo);
}

void menu(Console* console)
{
    printf("1. Display all the products!\n");
    printf("2. Add a new product!\n");
    printf("3. Delete a product!\n");
    printf("4. Update product's quantity!\n");
    printf("5. Update product's expiration date!\n");
    printf("6. Display all products whose name contains a given string sorted by quantity!\n");
    printf("7. Undo an operation!\n");
    printf("8. Redo an operation!\n");
    printf("9. Display all the products of a given category which expire in x days!\n");
    printf("E. Exit the program!");
    printf("The available types for the products are: dairy, sweets, meat, fruit");

}

void start(Console* console)
{

    bool done = false;

    while(done==false)
    {
        char command[100];

        printf("\n");
        printf("Command> ");
        scanf("%s", command);
        printf("\n");

        if(strlen(command)!=1)
            printf("Invalid command!\n");
        else
            switch(command[0])
            {
                case '0':
                    menu(console);
                    break;

                case '1':
                    display_products_ui(console);
                    break;
                case '2':
                    add_product_ui(console);
                    break;

                case '3':
                    delete_product_ui(console);
                    break;

                case '4':
                    update_products_quantity_ui(console);
                    break;

                case '5':
                    update_products_expiration_date_ui(console);
                    break;

                case '6':
                    search_elements_by_string_ui(console);
                    break;

                case '7':
                    undo_ui(console);
                    break;

                case '8':
                    redo_ui(console);
                    break;

                case '9':
                    display_products_by_category(console);
                    break;

                case 'E':

                    done = true;
                    break;

                default:
                    printf("Invalid command!\n");
            }
    }
}

