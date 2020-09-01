#include "program.h"

#define MAX_DIGITS_NUM 64

int num = MAX_DIGITS_NUM - 1;
int digits = MAX_DIGITS_NUM;
int binary[MAX_DIGITS_NUM] = {0};

struct number_format
{
    long num_dec;
    long num_oct;
    long num_hex;
    long num_bin;
};

struct number_format* num_format;

void program_init()
{
    input_info();
    // print_binary_dial();
}

void input_info()
{
    int chioce = 0;
    int tmp_num;
    printf("1 Dec transform others\n2 Hex transform others\n3 Quit\n");

    while (tmp_num = scanf("%d", &chioce))
    {

        switch (chioce)
        {
        case 1:
            printf("%d\n", chioce);
            break;
        case 2:
            printf("%d\n", chioce);
            break;
        case 3:
            return;
        default:
            printf("Error Usage\n");
            break;
        }
    }
}

void get_binary_num()
{

}

void print_binary_dial()
{
    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            printf("%d\t", num);
            num -= 4;
        }
        printf("\n");
        for (int i = 0; i < 4; i++)
        {
            for (int column = 0; column < 4; column++)
            {
                printf("%d ",binary[digits]);
                digits--;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void print_octal()
{
    printf("Oct: 0%lo", num_format->num_oct);
}

void print_decimal()
{
    printf("Dec: 0%ld", num_format->num_dec);
}

void print_hexadecimal()
{
    printf("Hex: 0x%lx", num_format->num_dec);
}