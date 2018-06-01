/*************************************************************************
	> File Name: camera.h
	> Author:
	> Mail:
	> Created Time:
 ************************************************************************/

#ifndef _CAMERA_H
#define _CAMERA_H

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

#include "dataqueue.h"
#include "capturePicture.h"
#ifdef __cplusplus
extern "C" {
#endif
#define vfe_camera 0
#define vin_camera 1
#define usb_camera 2

struct buffer
{
    void *start[3];
    size_t length[3];
};

typedef struct camerahdl
{
    int videofd;
    char video_path[32];
    int index;
    int camera_type;
    struct moduleAttach pipe;
    pthread_t tid;
    int enable;
    unsigned int video_width;
    unsigned int video_height;
    unsigned int pixelformat;
    unsigned int fps;
    unsigned int num_buffer;
    int64_t nPts;
    int nplanes;
    struct buffer *buffers;

    int capture_flag;
    char photo_path[64];
    struct capture picture;
}camera_hdl;

int cameraInit(camera_hdl *hdl);
int cameraStartCapture(camera_hdl *hdl);
int cameraStopCapture(camera_hdl *hdl);
int cameraRelease(camera_hdl *hdl);
void *CameraThread(void *argv);
#ifdef __cplusplus
}
#endif
#endif
