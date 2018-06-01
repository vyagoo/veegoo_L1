/*************************************************************************
	> File Name: muxer.h
	> Author:
	> Mail:
	> Created Time:
 ************************************************************************/

#ifndef _MUXER_H
#define _MUXER_H

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <linux/videodev2.h>
#include "vdecoder.h"
#include "memoryAdapter.h"
#include <pthread.h>
#include <semaphore.h>
#include <ctype.h>
#include <errno.h>
#include <CdxQueue.h>
#include <AwPool.h>
#include <CdxBinary.h>
#include <CdxMuxer.h>
#include "awencoder.h"

#include "RecorderWriter.h"
#include "dataqueue.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct _muxer
{
    int videoEos;
    int videoNum;

    int muxType;

    char pUrl[1024];

    CdxWriterT *pStream;
    CdxMuxerT *pMuxer;

    int exitFlag;

    pthread_t tid;
    struct moduleAttach pipe;

    VideoEncodeConfig *videoConfig;
    AudioEncodeConfig *audioConfig;
    unsigned char *extractDataBuff;
    unsigned int extractDataLength;

}muxer_handle;

#define AUDIO_INPUT (0)
#define VIDEO_INPUT (1)

int muxer_init(void *handle);
void *MuxerThread(void *param);
#ifdef __cplusplus
}
#endif
#endif
