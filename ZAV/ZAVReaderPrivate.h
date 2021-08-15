//
// Created by Zippo on 2021/8/15.
//
#pragma once

#ifndef ZPLAYER_ZAVREADERPRIVATE_H
#define ZPLAYER_ZAVREADERPRIVATE_H

#endif //ZPLAYER_ZAVREADERPRIVATE_H

extern "C" {
#include <libavformat/avformat.h>
}

class ZAVReaderPrivate {
public:
    AVFormatContext *formatCtx = nullptr;
};