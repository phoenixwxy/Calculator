#include "log.h"

#include <time.h>
#include <sys/time.h>
#include <string.h>

int g_log_level = 0;
unsigned char g_file_name[20] = {"./Log.log"};

void log_init()
{
    int result = error;
    // read config file
    //result = get_config_info()

    if (success == result)
    {

    }
    else
    {
        // default config
        g_log_level = set_log_level(Debug);
    }
    
}

int set_log_level(int log_level)
{
    g_log_level = log_level;
    return g_log_level;
}

void get_time(unsigned char *time_str)
{
    struct tm      t_systime     = {0};
    struct timeval t_time_val     = {0};
    time_t         tCurrentTime = {0};
	
    unsigned char  sz_usec[20] = {0};    // 微秒
	unsigned char  sz_msec[20] = {0};    // 毫秒

	if (time_str == NULL)
	{
	    return;
	}

    tCurrentTime = time(NULL);
    localtime_r(&tCurrentTime, &t_systime);   // localtime_r是线程安全的

    gettimeofday(&t_time_val, NULL);    
    sprintf(sz_usec, "%06ld", t_time_val.tv_usec);  // 获取微秒
    strncpy(sz_msec, sz_usec, 3);                // 微秒的前3位为毫秒(1毫秒=1000微秒)
    
    sprintf(time_str, "[%04d-%02d-%02d %02d:%02d:%02d.%3.3s]", 
            t_systime.tm_year+1900, t_systime.tm_mon+1, t_systime.tm_mday,
            t_systime.tm_hour, t_systime.tm_min, t_systime.tm_sec, sz_msec);
}

unsigned char *log_level_to_str(int log_level)
{
    if (0 > log_level && 5 < log_level)
    {
        return NULL;
    }

    switch (log_level)
    {
    case Error:
        return "Error";
    case Info:
        return "Info";
    case Warn:
        return "Warn";
    case Debug:
        return "Debug";
    case Verbose:
        return "Verbose";
    case Trace:
        return "Trace";
    
    default:
        return "Others";
    }
}

void write_log_file(unsigned char *file_name, const char *function_name,
                       unsigned int code_line, unsigned int log_level, unsigned char *content)
{
    FILE *p_log_file                    = NULL;
    unsigned char log_content[2048]     = {0};
    unsigned char time_str[128]              = {0};

    if (log_level > g_log_level)
    {
        return;
    }

    p_log_file = fopen(g_file_name, "at+");      // 打开文件, 每次写入的时候在后面追加
    if (NULL == p_log_file)
    {
        return;
    }

    get_time(&time_str);
    fputs(time_str, p_log_file);

    snprintf(log_content, sizeof(log_content) - 1, "[%s][%s][%s][%04d] %s\n",
                log_level_to_str(log_level), (strrchr(file_name, '/') + 1), function_name, code_line, content);

    fputs(log_content, p_log_file);
    fflush(p_log_file);
    fclose(p_log_file);

    p_log_file = NULL;

    return;
}