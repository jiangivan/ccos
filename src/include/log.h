#ifndef __LOG_H__
#define __LOG_H__

#include "stdio.h"
#include "log.h"

/*******************************************
* Log configure
*******************************************/
#define DEBUG_LEVEL_ERR		1
#define DEBUG_LEVEL_INFO 	2
#define DEBUG_LEVEL_DEBUG	3
#define DEBUG_LEVEL_ALL		4

//#define DEBUG_LEVEL_DETAIL

// debug level, the higher the more info to print
#define DEBUG_LEVEL	DEBUG_LEVEL_INFO

// to print apdu or not
#define PRINT_APDU_RESP

// temp buffer for convert in charString2ByteString when format file contents.
#define STATIC_TEMP_BUFFER

/******************************************/
#ifndef LOG_TAG
#define LOG_TAG	"REDTEA"
#endif


#ifndef DEBUG_LEVEL_DETAIL
#define PRINT(format,...) softsim_printf("[ %s ] "format,LOG_TAG,##__VA_ARGS__);
#else
#define PRINT(format,...) softsim_printf("[ %s ] [%s %s] [%s,%s,%d]: " format,LOG_TAG,__DATE__,__TIME__,__FILE__,__FUNCTION__,__LINE__,##__VA_ARGS__);
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_ALL
#define LOGA(format,...) PRINT(format,##__VA_ARGS__)
#else
#define LOGA(format,...) 
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG
#define LOGD(format,...) PRINT(format,##__VA_ARGS__)
#else
#define LOGD(format,...) 
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_INFO
#define LOGI(format,...) PRINT(format,##__VA_ARGS__)
#else
#define LOGI(format,...) 
#endif

#if DEBUG_LEVEL >= DEBUG_LEVEL_ERR
#define LOGE(format,...) PRINT(format,##__VA_ARGS__)
#else
#define LOGE(format,...) 
#endif

#define LOGD_FUNC()		LOGD("%s", __FUNCTION__)
#define LOGD_INFO(s)		LOGD("%s", s)
#define LOGE_ERR(s)		LOGE("%s", s)
#define LOGD_STR(s)		LOGD("%s", s)
#define LOGI_STR(s)		LOGI("%s", s)
#define LOGA_STR(s)		LOGA("%s", s)

#endif /* __LOG_H__ */
