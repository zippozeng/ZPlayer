//
// Created by Zippo on 2021/8/15.
//

#include "ZAV.h"
#include "ZAVReaderPrivate.h"
#include "ZAVPacketPrivate.h"
#include "ZAVStreamPrivate.h"

ZAVReader::ZAVReader() {
    imp = new ZAVReaderPrivate();
    imp->formatCtx = avformat_alloc_context();
}

ZAVReader::~ZAVReader() {
    if (imp != nullptr && imp->formatCtx != nullptr) {
        avformat_free_context(imp->formatCtx);
        imp->formatCtx = nullptr;
    }
    if (imp != nullptr) {
        delete imp;
        imp = nullptr;
    }
}

int ZAVReader::open(const char *path) {
    if (imp == nullptr || imp->formatCtx == nullptr) {
        return -1;
    }
    int ret = avformat_open_input(&imp->formatCtx, path, nullptr, nullptr);
    if (!ret) {
        avformat_find_stream_info(imp->formatCtx, nullptr);
    }
    return ret;
}

int ZAVReader::close() {
    if (imp == nullptr || imp->formatCtx == nullptr) {
        return -1;
    }
    avformat_close_input(&imp->formatCtx);
    return 0;
}

int ZAVReader::read(ZAVPacket *packet) {
    if (imp == nullptr || imp->formatCtx == nullptr) {
        return -1;
    }
    int ret = av_read_frame(imp->formatCtx, packet->imp->pkt);
    return ret;
}

int ZAVReader::getStreamCount() {
    return imp->formatCtx->nb_streams;
}

int ZAVReader::getStream(ZAVStream *stream, int streamId) {
    if (imp == nullptr) {
        return -1;
    }
    AVStream *ffmpegStream = imp->formatCtx->streams[streamId];
    stream->index = ffmpegStream->index;
    avcodec_parameters_copy(stream->imp->codecpar, ffmpegStream->codecpar);
    return 0;
}
