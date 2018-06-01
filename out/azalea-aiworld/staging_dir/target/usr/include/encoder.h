#ifndef _ENCODER_H_
#define _ENCODER_H_

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

#include "common.h"
#include "dataqueue.h"
#ifdef __cplusplus
extern "C" {
#endif
#define ALIGN_16B(x) (((x) + (15)) & ~(15))


typedef struct EncoderContext
{
    AwEncoder* mAwEncoder;

    VideoEncodeConfig videoConfig;
    AudioEncodeConfig audioConfig;

    unsigned char* extractDataBuff;
    unsigned int extractDataLength;

    AwPoolT *pool;
    CdxQueueT *dataQueue;

    int exitFlag;

    int saveframe_Flag;
	int recordFlag;

    char *save_path;

    int frame_count;

}EncoderContext;

typedef struct _encoder
{
    pthread_t tid;
    int enable;

    int ENCODE_FMT;
    int SOURCE_FMT;
    int videoWidth;
    int videoHeight;

    int flag_UsePhyBuf;

    long long timestamp_now;
    long long timestamp_start;
    long long timestamp_interval;

    EncoderContext encoder_context;

    struct moduleAttach pipe;

    EncDataCallBackOps mEncDataCallBackOps;

}encoder_handle;


int encoder_init(void *handle);
int encoder_quit(void *param);
void *EncoderThread(void *param);
#ifdef __cplusplus
}
#endif
#endif
