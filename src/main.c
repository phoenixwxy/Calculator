#include <stdio.h>
#include <string.h>

#include "calculator_terminal.h"
#include "log.h"

#include "zlog.h"
#include "pzlog.h"


int main(int argc, char** argv)
{
    // int a = 1;
    // int rc;
    // log_init();

    // rc = testlog_init();
    // if (rc < 0)
    // {
    //     printf("test rc\n");
    //     return rc;
    // }

    // pzlog_info("test 123");
    // pzlog_info("test a = %d", a);

    // zlog_info(c, "hello, zlog");

    // dzlog_init("./test.conf", "log");
    // dzlog_set_category("log");    

    initialize_cal_terminal(argc, argv);
    
    
    // log_to_file(Verbose, "test");

    // int rc;
    // rc = zlog_init("test.conf");
    // if (rc) {
    //     printf("init failed\n");
    //     return -1;
    // }

    // c = zlog_get_category("log");

    // if (!c) {
    //     printf("get cat fail\n");
    //     zlog_fini();
    //     return -2;
    // }

    // zlog_fini();
    return 0;
}