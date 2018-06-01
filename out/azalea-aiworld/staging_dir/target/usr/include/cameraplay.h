/*************************************************************************
	> File Name: cameraplay.h
	> Author:
	> Mail:
	> Created Time:
 ************************************************************************/

#ifndef _CAMERAPLAY_H
#define _CAMERAPLAY_H

#include "camera.h"
#include "display.h"
#include "encoder.h"
#include "muxer.h"
#include "decoder.h"
#include "parser.h"
#include "log.h"

#define ALIGN_16B(x) (((x) + (15)) & ~(15))

#define AUDIO_INPUT (0)
#define VIDEO_INPUT (1)

enum threadState
{
    ConfigInit = 0,
    preview,
    recording,
};

struct cameraplay
{
    int enable;
    enum threadState state;

    camera_hdl capture;
    displayhdl display;
    encoder_handle encoder;
    muxer_handle muxer;
    decoder_handle decoder;
    parser_handle parser;

    struct moduleAttach *videopipe;
};

#endif
