/*************************************************************************
	> File Name: camera_disp.h
	> Author:
	> Mail:
	> Created Time: 2017年09月21日 星期四 10时16分40秒
 ************************************************************************/

#ifndef _CAMERA_DISP_H
#define _CAMERA_DISP_H

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
#include <pthread.h>
#include <semaphore.h>
#include <ctype.h>
#include <errno.h>
#include <linux/videodev2.h>
#include <ion_mem_alloc.h>
#include "videoOutPort.h"

#include "convert.h"
#include "dataqueue.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct _disphdl
{
    pthread_t tid;
    int enable;

    struct moduleAttach pipe;

    int flag_UsePhyBuf;

    int index;
	dispOutPort *DisPort;

    videoZorder layer;

    videoSource source_video;

    VoutRect preview_rect;

    unsigned char *disp_yuvdata;

    int data_len;

    int width;

    int height;

    int win_width;
    int win_height;

}displayhdl;

int dispInit(void *handle);
int disp_set_rect(void *handle);
int disp_set_zorder(void *handle);
int v_CreateGaryBuf(void *handle);
void v_GetGaryData(void* handle, char* pixels);
int v_DestoryGaryBuf(void *handle);
void *DisplayThread(void *argv);
#ifdef __cplusplus
}
#endif
#endif
