//
// Created by Alexandra on 3/2/2021.
//

#include "domain.h"
#include <stdio.h>
#include <string.h>

Product createProduct(char name[], char type[], int quantity, char date[])
{

    Product p;
    strcpy(p.name, name);
    strcpy(p.type, type);
    p.quantity = quantity;
    strcpy(p.date, date);

    return p;
}

void assign_values(Product* new_product, Product product)
{
    strcpy(new_product->name, product.name);
    strcpy(new_product->type, product.type);
    new_product->quantity = product.quantity;
    strcpy(new_product->date, product.date);
}

char* getName(Product* p)
{
    return p->name;
}

char* getType(Product* p)
{
    return p->type;
}

int getQuantity(Product* p)
{
    return p->quantity;
}

char* getDate(Product* p)
{
    return p->date;
}

//void toString(Product r, char str[])
//{
//    sprintf(str, "Name: %s  Type: %s  Quantity: %d  Expiration date: %s", r.name, r.type, r.quantity, r.date);
//}
