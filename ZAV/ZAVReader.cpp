//
// Created by Zippo on 2021/8/15.
//

#include "ZAV.h"

ZAVReader::ZAVReader() {
    formatCtx = avformat_alloc_context();
}

ZAVReader::~ZAVReader() {
    if (formatCtx != nullptr) {
        avformat_free_context(formatCtx);
        formatCtx = nullptr;
    }
}

int ZAVReader::open(const char *path) {
    if (formatCtx == nullptr) {
        return -1;
    }
    int ret = avformat_open_input(&formatCtx, path, nullptr, nullptr);
    if (!ret) {
        avformat_find_stream_info(formatCtx, nullptr);
    }
    return ret;
}

int ZAVReader::close() {
    if (formatCtx == nullptr) {
        return -1;
    }
    avformat_close_input(&formatCtx);
    return 0;
}

int ZAVReader::read(ZAVPacket *packet) {
    return 0;
}
