//
// Created by Zippo on 2021/8/15.
//

#ifndef ZPLAYER_ZAV_H
#define ZPLAYER_ZAV_H

#endif //ZPLAYER_ZAV_H

class ZAVPacketPrivate;

class ZAVPacket {
public:
    ZAVPacket();

    ~ZAVPacket();

    int getStreamIndex();

    ZAVPacketPrivate *imp = nullptr;
};


class ZAVStreamPrivate;

class ZAVStream {
public:
    ZAVStream();

    ~ZAVStream();

    int index = -1;
    ZAVStreamPrivate *imp = nullptr;
};

class ZAVFramePrivate;

class ZAVFrame {
public:
    ZAVFrame();

    ~ZAVFrame();

    ZAVFramePrivate *imp = nullptr;
};

class ZAVReaderPrivate;

class ZAVReader {
public:
    ZAVReader();

    ~ZAVReader();

    int open(const char *path);

    int getStreamCount();

    int getStream(ZAVStream *steam, int streamId);

    int close();

    int read(ZAVPacket *packet);

private:
    ZAVReaderPrivate *imp = nullptr;
};

class ZAVDecoderPrivate;

class ZAVDecoder {
public:
    ZAVDecoder();

    ~ZAVDecoder();

    int init(ZAVStream *stream);

    int sendPacket(ZAVPacket *pkt);

    int receiveFrame(ZAVFrame *frame);

    int close();

private:
    ZAVDecoderPrivate *imp = nullptr;
};