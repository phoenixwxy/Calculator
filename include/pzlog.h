#ifndef __PZLOG_H
#define __PZLOG_H

#include <stdio.h>

#include "zlog.h"

zlog_category_t *c;

#define pzlog_fatal(...)                                \
    if (c != NULL)                                      \
        zlog_fatal(c, __VA_ARGS__);                     \
    else                                                \
        testlog_init()

#define pzlog_error(...)                                \
    if (c != NULL)                                      \
        zlog_error(c, __VA_ARGS__);                     \
    else                                                \
        testlog_init()

#define pzlog_warn(...)                                 \
    if (c != NULL)                                      \
        zlog_warn(c, __VA_ARGS__);                      \
    else                                                \
        testlog_init()

#define pzlog_info(...)                                 \
    if (c != NULL)                                      \
        zlog_info(c, __VA_ARGS__);                      \
    else                                                \
        testlog_init()

#define pzlog_debug(...)                                \
    if (c != NULL)                                      \
        zlog_debug(c, __VA_ARGS__);                     \
    else                                                \
        testlog_init()

#define pzlog_notice(...)                               \
    if (c != NULL)                                      \
        zlog_notice(c, __VA_ARGS__);                    \
    else                                                \
        testlog_init()

int testlog_init();
void testlog_destroy();

#endif