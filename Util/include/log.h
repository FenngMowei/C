#ifndef _LOG_H_
#define _LOG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum logLevel {
    INFO = 1,
    ERROR = 2,
} LOG_LEVEL;

LogImp g_logImp = Log2Control;

typedef void (*LogImp)(LOG_LEVEL type, int32_t line, const char* fun, const char* file, char* fmt, ...);

void Log2File(LOG_LEVEL level, int32_t line, const char* fun, const char* file, char* fmt, ...);

void Log2Control(LOG_LEVEL level, int32_t line, const char* fun, const char* file, char* fmt, ...);

#define LOG_INFO(fmt, ...)                                                    \
    {                                                                         \
        g_logImp(INFO, __LINE__, __FUNCTION__, __FILE__, fmt, ##__VA_ARGS__); \
    }

#define LOG_ERROR(fmt, ...)                                                    \
    {                                                                          \
        g_logImp(ERROR, __LINE__, __FUNCTION__, __FILE__, fmt, ##__VA_ARGS__); \
    }

#ifdef __cplusplus
}
#endif

#endif // _LOG_H_