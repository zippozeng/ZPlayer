//
// Created by Zippo on 2021/8/22.
//
#pragma once

#ifndef ZPLAYER_ZAVSTREAMPRIVATE_H
#define ZPLAYER_ZAVSTREAMPRIVATE_H

#endif //ZPLAYER_ZAVSTREAMPRIVATE_H
extern "C" {
#include <libavformat/avformat.h>
}

class ZAVStreamPrivate {
public:
    AVCodecParameters *codecpar = nullptr;
};