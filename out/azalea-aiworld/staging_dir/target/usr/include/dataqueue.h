#ifndef _DATAQUEUE_H
#define _DATAQUEUE_H

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
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <CdxQueue.h>
#include <AwPool.h>
#include <typedef.h>
#include "CdxMuxer.h"
#include <linux/videodev2.h>
#include "vdecoder.h"
#include "CdxAtomic.h"
#ifdef __cplusplus
extern "C" {
#endif
struct camerabuffer
{
    void *start;
    size_t length;
};

enum moduleType{
    CSI_CAMERA  = 0x01,
    UVC_CAMERA  = 0x02,
    AUDIO       = 0x04,
    PARSER      = 0x08,
    DECODER     = 0x10,
    ENCODER     = 0x20,
    SCREEN      = 0x40,
    MUXER       = 0x80,
};

struct outputSrc{
    CdxQueueT *srcQueue;        /* next module data source */
    enum moduleType sinkType;   /* next module data type */
    struct outputSrc *next;
};

struct moduleAttach{
	struct outputSrc *output;   /* next module data source */
    AwPoolT *sinkDataPool;      /* self module data pool */
    CdxQueueT *sinkQueue;       /* self module data queue */
    unsigned int type;          /* sele module type */
    unsigned int src_type;      /* input data module type */
};

struct videoPacket{
    int video_fd;
    struct v4l2_buffer *buf;
    struct camerabuffer *buffers;
    unsigned int video_width;
    unsigned int video_height;
    unsigned int format;
};

struct decoderPacket{
    VideoDecoder *decoder;
    VideoPicture *picture;
};

struct modulePacket{
    enum moduleType packet_type;  /* packet data type */
    cdx_atomic_t ref;                /* the number of packet references */
    void *buf;
};

/* media packet */
struct MediaPacket{
	int buf_index;
    unsigned int width;
    unsigned int height;
    char *Vir_Y_addr;
    char *Vir_C_addr;
    size_addr Phy_Y_addr;
    size_addr Phy_C_addr;
    int data_len;
    int bytes_used;
	int format;
    int64_t nPts;
	int fps;

    /* free */
    int video_fd;
    VideoDecoder *decoder;
    VideoPicture *picture;
};


struct queuePacket{
    enum moduleType data_type;
    void *buf;
    unsigned int buflen;
};

int modules_link(struct moduleAttach *module_1, struct moduleAttach *module_2, ...);
int modules_unlink(struct moduleAttach *module_1, struct moduleAttach *module_2, ...);
int module_push(struct moduleAttach *module, struct modulePacket *mPacket);
void *module_pop(struct moduleAttach *module);
int module_InputQueueEmpty(struct moduleAttach *module);
int free_packet(struct modulePacket *mPacket);

#ifdef __cplusplus
}
#endif
#endif
