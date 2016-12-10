/****************************************************************************
File name: 		myprintf.h
Author: 		
Version: 		
Description: 	格式化输出(printf)相关函数声明
Others: 		无
History:
****************************************************************************/

#ifndef _MYPRINTF_H
#define _MYPRINTF_H

#include <stdarg.h>

typedef enum {
    MYPRINT_OK = 0,
    MYPRINT_WRITE_ERR = -1,
    MYPRINT_NULL_PTR = -2,
} myprintf_result_t;

typedef enum {
    MYPRINT_FLAGS_NONE             = 0x0000,
    MYPRINT_FLAGS_NO_TRAILING_NULL = 0x0001,
} myprintf_flags_type;

int myprintf (const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, unsigned int maxLen, const char *format, ...);

int testPrintf (void);

#endif
