#include <stdio.h>

#include "log.h"

int main(int argc, char** argv)
{
    log_init();
    
    log_to_file(Error, "test");
    log_to_file(Info, "test");
    log_to_file(Verbose, "test");
    return 0;
}