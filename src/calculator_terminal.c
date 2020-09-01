#include "calculator_terminal.h"
// #include "calculator.h"
#include "program.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

const char * VERSION = "0.0.1";

//定义长选项
static struct option long_options[] = 
{
    {"help",        no_argument, NULL, 'h'},
    {"version",     no_argument, NULL, 'v'},
    {"program",     no_argument, NULL, 'p'}
    // {"number",required_argument,NULL,'n'}
};

void initialize_cal_terminal(int argc, char** argv)
{
    int chioce = 0;
    int index = 0;

    while (EOF != (chioce = getopt_long(argc, argv, "hvp", long_options, &index)))
    {
        select_chioce(chioce);
    }



    // printf("\t\t\t\t\tCalculator\n\t\t\t\t\t   V0.1\n\t\t\t\t\t  Phoenix\n");
    // printf("\t\t\t\t\t1、General\n\t\t\t\t\t2、science\n\t\t\t\t\t3、Program\n\t\t\t\t\t4、Exit\n");


}

void select_chioce(int chioce)
{
    switch (chioce)
    {
    case 'h':
        function_help();
        break;
    case 'v':
        function_version();
        break;
    case 'p':
        function_program();
        break;

    default:
        printf("Error Usage!\n");
        function_help();
        break;
    }
}

void function_help()
{
    printf("Usage: Calculator [OPTION]...\n");
    exit(0);
}

void function_version()
{
    printf("Version: %s\n", VERSION);
    exit(0);
}

void function_program()
{
    program_init();
}