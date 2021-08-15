//
// Created by Zippo on 2021/8/15.
//
#pragma once

#ifndef ZPLAYER_ZAVPACKETPRIVATE_H
#define ZPLAYER_ZAVPACKETPRIVATE_H

#endif //ZPLAYER_ZAVPACKETPRIVATE_H
extern "C" {
#include <libavcodec/packet.h>
}

class ZAVPacketPrivate {
public:
    AVPacket *pkt = nullptr;
};