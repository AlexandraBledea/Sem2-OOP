//
// Created by Alexandra on 3/3/2021.
//
#pragma once
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int validate_product_name(char name[])
{
    if(strlen(name) < 1)
        return 0;
    for(int i=0; i<strlen(name); i++)
        if (isdigit(name[i]))
            return 0;
    return 1;
}

int validate_product_quantity(char quantity[])
{
    int new_quantity = 0;
    if(strlen(quantity) < 1)
        return 0;
    if(strlen(quantity) >= 1)
        if(quantity[0]=='0')
            return 0;
    for(int i=0; i<strlen(quantity); i++)
        if(isalpha(quantity[i]))
            return 0;
    new_quantity = strtol(quantity, NULL, 10);
    if(new_quantity == 0)
        return 0;
    return new_quantity;

}

int validate_product_type(char type[])
{
    const char products_types[4][7] = {"dairy", "sweets", "fruit", "meat"};
    for(int i = 0; i < 4; i++)
        if (strcmp(type, products_types[i]) == 0)
            return 1;
    return 0;
}

int validate_expiration_date(char date[])
{
    char str1[100], str2[100], str3[100];
    int d, m, y;
    if(strlen(date) != 10)
        return 0;

    if(date[2] != '.')
        return 0;
    if(date[5] != '.')
        return 0;

    if(date[0] == '0' && date[1] == '0')
        return 0;

    if(date[3] == '0' && date[4] == '0')
        return 0;

    if(date[6] == 0 &&  date [7] == 0 && date[8] == 0 && date [9] == 0)
        return 0;

    str1[0] = date[0];
    str1[1] = date[1];
    str1[2] = 0;
    d = strtol(str1, NULL, 10);
    if(d <= 0)
        return 0;
    if(d > 31)
        return 0;

    str2[0] = date[3];
    str2[1] = date[4];
    str2[2] = 0;
    m = strtol(str2, NULL, 10);

    if (m <= 0)
        return 0;
    if(m > 12)
        return 0;

    str3[0] = date[6];
    str3[1] = date[7];
    str3[2] = date[8];
    str3[3] = date[9];
    y = strtol(str3, NULL, 10);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(y < tm.tm_year+1900)
        return 0;

    if(y == tm.tm_year+1900 && d == tm.tm_mday && m == tm.tm_mon+1)
        return 0;

    if(isalpha(date[0]) || isalpha(date[1]) || isalpha(date[3]) || isalpha(date[4]) || isalpha(date[6]) ||
       isalpha(date[7]) || isalpha(date[8]) || isalpha(date[9]))
        return 0;

    return 1;

}

int validate_criteria(criteria)
{
    if(criteria != 1 && criteria != 2)
        return 0;
    return 1;
}