#include "pzlog.h"

int testlog_init()
{
    int rc;
    rc = zlog_init("test.conf");
    if (rc) {
        printf("init failed\n");
        return -1;
    }

    c = zlog_get_category("log");

    if (!c) {
        printf("get cat fail\n");
        zlog_fini();
        return -2;
    }
    // printf("phoenix 123");
}

void testlog_destroy()
{
    zlog_fini();
}