/*************************************************************************
	> File Name: parser.h
	> Author:
	> Mail:
	> Created Time:
 ************************************************************************/

#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <cdx_log.h>
#include "cdx_config.h"
#include "CdxParser.h"
#include "vdecoder.h"
#include "memoryAdapter.h"

#include "dataqueue.h"
#ifdef __cplusplus
extern "C" {
#endif
#define PARSER_MAX_STREAM_NUM 1024

enum ParserType{
    PARSER_NULL,
    PARSER_FILE,
    PARSER_FRAME,
};

typedef struct _parserhandle{
    struct moduleAttach pipe;
    pthread_t tid;
    int enable;
    enum ParserType parser_type;
    char url[128];
    CdxDataSourceT source;
    int exitflag;
    pthread_mutex_t parserMutex;
    CdxParserT *parser;
    CdxStreamT *stream;
    CdxMediaInfoT mediaInfo;
    VideoDecoder *decoder;
}parser_handle;

int parser_init(void *handle, char *url, void *param);
void *parser_thread(void *argv);
#ifdef __cplusplus
}
#endif
#endif
