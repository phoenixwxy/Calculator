#include "calculator.h"

#include <math.h>

double g_num1 = 0.0;
double g_num2 = 0.0;

double get_input(double num1, char symbol, double num2)
{
    g_num1 = num1;
    g_num2 = num2;
    return judg_operator(symbol);
}

double judg_operator(char input)
{
    if (input == '+')
    {
        return g_num1 + g_num2;
    }
    else if (input == '-')
    {
        return g_num1 - g_num2;
    }
    else if (input == '*')
    {
        return g_num1 * g_num2;
    }
    else if (input == '/')
    {
        if (0 == g_num2)
        {
            fprintf(stderr, "除数为 0 退出运行...\n");
            exit(-1);
        }
        return g_num1 / g_num2;
    }
    else if (input == '%')
    {
        return fmod(g_num1, g_num2);
    }
    else if (input == '(')
    {
        return;
    }
    else if (input == ')')
    {
        return;
    }
    
}