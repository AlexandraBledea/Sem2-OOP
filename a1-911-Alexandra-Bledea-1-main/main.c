//
// Created by Alexandra on 2/22/2021.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct subsequence
{
    int final, start, max_length;
};

typedef struct subsequence Struct;

void menu()
{
    printf("Type 1 for reading a vector\n");
    printf("Type 2 for printing the exponent of a prime number p from the decomposition in prime factors "
           "of a given number n\n");
    printf("Type 3 for finding the longest contiguous subsequence such that any two consecutive elements are relatively "
           "prime.\n");
    printf("Type 4 for exiting the program\n");
}

void read_vector(int n, int vector[])
/*
 * With this function we read the elements of a vector
 * n -> the number of elements of the vector
 * vector -> the vector in which we store the values we read
 */
{
    for(int i = 1; i <= n; i++)
        scanf("%d", &vector[i]);

}

int gcd(int a, int b)
/*
 * With this function we compute the greatest common divisor of two given numbers
 * a -> first number
 * b -> second number
 */
{
    while(a != b)
    {
        if(a > b)
            a = a - b;
        if(b > a)
            b = b - a;
    }
    return a;
}

Struct longest_subsequence(int n, int vector[101])
/*
 * With this function we compute the start position, the end position and the max length of the longest subsequence
 * with relatively prime consecutive terms
 * n -> the number of elements from the vector
 * vector -> the vector for whose elements we compute the longest subsequence of consecutive relatively prime terms
 */
{
    Struct s;
    s.max_length = -1;
    s.start = 0;
    s.final = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
            if(gcd(vector[j-1], vector[j]) == 1)
            {
                if (j - i + 1 > s.max_length)
                {
                    s.max_length = j - i + 1;
                    s.start = i;
                    s.final = j;
                }
            }
            else
                break;

    }
    return s;
}

int check_prime(int number)
/*
 * With this function we check if a number is prime or not
 * number -> the number we want to check if it's prime or not
 */
{
    if(number == 1)
        return 0;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number) return 0;
    }
    return 1;
}

int decompose(int number, int exponent)
/*
 * With this function we decompose a number in prime factors
 * number -> the number we want to decompose
 * exponent -> represents the prime number for which we want to find the exponent in the decomposition
 */
{
    int sir[21] = {0};
    int divisor = 2;
    while(number != 1)
    {
        while(number%divisor==0)
        {
            number /= divisor;
            sir[divisor]++;
        }
        divisor++;
    }

    return sir[exponent];
}

int main()
/*
 * This is the main of the function structured as a menu console with 4 available commends.
 */
{
    bool done = false;
    int vector[101] = {0};

    menu();

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
            switch(command[0]) {
                case '1':
                    int number_of_elements = 0;
                    printf("Type the number of elements you want the vector to have: ");
                    scanf("%d", &number_of_elements);
                    read_vector(number_of_elements, vector);
                    break;

                case '2':
                    int number = 0;
                    int exponent = 0;
                    printf("Read the number you want to decompose in prime factors:\n");
                    scanf("%d", &number);
                    printf("Read the prime number for which you want to display the exponent from the decomposition\n");
                    scanf("%d", &exponent);
                    if (check_prime(exponent) == 0)
                    {
                        printf("The given number is not a prime number!");
                        break;
                    }
                    exponent = decompose(number, exponent);
                    printf("The exponent is: %d\n", exponent);
                    break;

                case '3':
                    Struct result;
                    for(int i = 1; i <= number_of_elements; i++)
                        printf("%d ", vector[i]);
                    printf("\n");
                    result = longest_subsequence(number_of_elements, vector);
                    if(result.max_length > 1)
                    {
                        for(int i = result.start; i <= result.final; i++)
                            printf("%d ", vector[i]);
                    }
                    else
                    {
                        printf("There is no sequence where the consecutive numbers are relatively prime!");
                        break;
                    }
                    break;

                case '4':
                    done = true;
                    break;

                default:
                    printf("Invalid command!\n");
            }
    }
    return 0;
};


//        if(command == '1')
//        {
//            read_vector();
//            correct_command = true;
//        }
//
//        else
//
//        if(command == '2')
//        {
//            function_1();
//            correct_command = true;
//        }
//
//        else
//
//        if(command == '3')
//        {
//            function_2();
//            correct_command = true;
//        }
//
//        else
//
//        if(command == '4')
//        {
//            done = true;
//            correct_command = true;
//        }
//
//        else
//
//        if(correct_command == false)
//            printf("Invalid command!\n");
//