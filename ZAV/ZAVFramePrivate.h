//
// Created by Zippo on 2021/8/22.
//

#ifndef ZPLAYER_ZAVFRAMEPRIVATE_H
#define ZPLAYER_ZAVFRAMEPRIVATE_H

#endif //ZPLAYER_ZAVFRAMEPRIVATE_H
extern "C" {
#include <libavformat/avformat.h>
}

class ZAVFramePrivate {
public:
    AVFrame *frame = nullptr;
};