//
// Created by Zippo on 2021/8/16.
//

#include "ZAV.h"
#include "ZAVDecoderPrivate.h"
#include "ZAVStreamPrivate.h"

ZAVDecoder::ZAVDecoder() {
    imp = new ZAVDecoderPrivate();
    imp->codecContext = avcodec_alloc_context3(nullptr);
}

ZAVDecoder::~ZAVDecoder() {
    if (imp != nullptr && imp->codecContext != nullptr) {
        avcodec_free_context(&imp->codecContext);
        imp->codecContext = nullptr;
    }
    if (imp == nullptr) {
        delete imp;
        imp = nullptr;
    }
}

int ZAVDecoder::init(ZAVStream *stream) {
    if (imp == nullptr) {
        return -1;
    }
    avcodec_parameters_to_context(imp->codecContext, stream->imp->codecpar);
    AVCodec *codec = avcodec_find_decoder(imp->codecContext->codec_id);
    int ret = avcodec_open2(imp->codecContext, codec, nullptr);
    if (ret) {
        printf("avcodec_open2 failure retc:%d", ret);
        return -1;
    }
    return 0;
}

int ZAVDecoder::close() {
    if (imp == nullptr) {
        return 0;
    }
    return avcodec_close(imp->codecContext);
}
