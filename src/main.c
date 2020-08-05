#include <stdio.h>

#include "log.h"

int main(int argc, char** argv)
{
    
    log_to_file(Error, "test");
    return 0;
}