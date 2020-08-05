#ifndef __LOG_H
#define __LOG_H

#include <stdio.h>

#define success     0
#define error       1

#define Error    0
#define Info     1
#define Warn     2
#define Debug    3
#define Verbose  4
#define Trace    5



// 函数宏定义
#define log_to_file(level, msg)  write_log_file(__FILE__, __FUNCTION__, __LINE__, level, msg)

void                log_init();
int                 set_log_level(int log_level);
void                get_time(unsigned char *time_str);
unsigned char       *log_level_to_str(int log_level);
void                write_log_file(unsigned char *file_name, const char *function_name,
                                    unsigned int code_line, unsigned int log_level, unsigned char *content);

#endif