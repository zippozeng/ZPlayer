//
// Created by Zippo on 2021/8/15.
//

#ifndef ZPLAYER_ZAV_H
#define ZPLAYER_ZAV_H

#endif //ZPLAYER_ZAV_H
extern "C" {
#include <libavformat/avformat.h>
}

class ZAVPacket {
public:
    ZAVPacket();

    ~ZAVPacket();

    AVPacket *pkt = nullptr;
};

class ZAVReader {
public:
    ZAVReader();

    ~ZAVReader();

    int open(const char *path);

    int close();

    int read(ZAVPacket *packet);

private:
    AVFormatContext *formatCtx = nullptr;
};