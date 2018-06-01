/*************************************************************************
	> File Name: decoder.h
	> Author:
	> Mail:
	> Created Time:
 ************************************************************************/

#ifndef _DECODER_H
#define _DECODER_H

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
typedef struct _decoder{
    pthread_t tid;
    pthread_t read_tid;
    int enable;

    int SOURCE_FMT;

    int DECODE_FMT;

    int ScaleDownEn;

    VideoDecoder *pVideo;

    struct moduleAttach pipe;

    int fail_decoder;

	int fps;
	int curr_bufId;
	int64_t nPts;
    unsigned int frame_size;
    unsigned int photo_width;
    unsigned int photo_height;

    char *Vir_Y_Addr;
    char *Vir_C_Addr;

    size_addr Phy_Y_Addr;
    size_addr Phy_C_Addr;

    int frame_count;
    VideoPicture *videoPicture;

}decoder_handle;

int decoder_init(void *decoder, void *mediainfo);
void *decoderThread(void *param);
//void *read_decoder_Thread(void *argv);

#ifdef __cplusplus
}
#endif
#endif
