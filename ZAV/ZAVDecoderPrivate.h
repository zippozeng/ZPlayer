//
// Created by Zippo on 2021/8/16.
//
#pragma once

#ifndef ZPLAYER_ZAVDECODERPRIVATE_H
#define ZPLAYER_ZAVDECODERPRIVATE_H

#endif //ZPLAYER_ZAVDECODERPRIVATE_H
extern "C" {
#include <libavcodec/avcodec.h>
}

class ZAVDecoderPrivate {
public:
    AVCodecContext *codecContext = nullptr;
};