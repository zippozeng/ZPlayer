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