#include <stdio.h>
#include <string.h>

#include "calculator_terminal.h"
#include "log.h"

#include "zlog.h"

int main(int argc, char** argv)
{
    log_init();
    
    initialize_cal_terminal();
    // log_to_file(Error, "test");
    // log_to_file(Info, "test");
    // log_to_file(Verbose, "test");
    return 0;
}