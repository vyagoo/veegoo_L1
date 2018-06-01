#ifndef _CAPTURE_PICTURE_H_
#define _CAPTURE_PICTURE_H_

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

#include "log.h"
#include "dataqueue.h"

#define ALIGN_16B(x) (((x) + (15)) & ~(15))

struct capture{
    int dstWidth;
    int dstHeight;
    struct MediaPacket *packet;
};

int captureJpegPhoto(struct capture *hdl,char *savePath);

#endif
