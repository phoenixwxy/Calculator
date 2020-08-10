#include "calculator_terminal.h"
#include "calculator.h"

void initialize_cal_terminal()
{
    double num1 = 0.0, num2 = 0.0, result = 0.0;
    char  symbol;
    printf("\t\t\t\t\tCalculator\n\t\t\t\t\t   V0.1\n\t\t\t\t\t  Phoenix\n");

    scanf("%lf%c%lf", &num1, &symbol, &num2);
    result = get_input(num1, symbol, num2);
    printf("%f", result);
}
