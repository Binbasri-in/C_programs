/*
 * A simple calculater that takes two numbers given by the user and excecute the needed operation
 * Get the numbers and operation from user by command line input
 * Print the result to the screen
 * 
 * @author Mohammed Ali Binbasri
 * @date 01.07.2022
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // declare the operation to use it throught the program
    int operation;
    //Check if the program is used ccorrectly
    if (argc == 1)
    {
        // explain how the program works
        printf("Usage: ./calculations first_number operation second_number\noperations(+,-,/,'*')(add, subtracte, multiply, divide)\nNote: to use * you have to put it in quets '*'\n");
        return 1;

    }
    else
    {
        //check 3 inputs are entered
        if (argc != 4)
        {
            printf("input the values correctly, use ./calculations to see the usage\n");
            return 2;
        }
        // check each input is correct
        // check first CLI is only numbers
        for (int i = 0,l = strlen(argv[1]); i < l; i++)
        {
            // each one have to be a number
            if (isdigit(argv[1][i]) == 0)
            {
                // if anyone is not a numer stop the program and raise an error
                printf("input should be numbers only\n");
                return 3;
            }
        }
        // check second CLI is only one of these operations (+,-,/,*)
        operation = argv[2][0];
        if (operation != 43 && operation != 42 && operation != 45 && operation != 47)
        {
            // if any other character stop the program and raise an error
            printf("Program support only these operations (+,-,/,*)\n");
            return 4;
        }
        // check third CLI is only numbers
        for (int i = 0,l = strlen(argv[3]); i < l; i++)
        {
            // each one have to be a number
            if (isdigit(argv[3][i]) == 0)
            {
                // if anyone is not a numer stop the program and raise an error
                printf("input should be numbers only\n");
                return 3;
            }
        }
    }

    // store all input in the given variable
    float n1 = atof(argv[1]);

    float n2 = atof(argv[3]);

    // declare the variable where the result of calculating will be stored in
    float answer;
    // do the requested calculatios
    if ((int)operation == 43)
    {
        answer = n1 + n2;
    }
    else if (operation == 45)
    {
        answer = n1 - n2;
    }
    else if (operation == 42)
    {
        answer = n1 * n2;
    }
    else if (operation == 47)
    {
        answer = (float)n1 / n2;
    }
    else
    {
        answer = 0000000;
    }
    // print out the full operation with result
    printf("%f %c %f = %f\n", n1, operation, n2, answer);

}