//
// Created by Zippo on 2021/8/22.
//

#include "ZAV.h"
#include "ZAVStreamPrivate.h"

ZAVStream::ZAVStream() {
    imp = new ZAVStreamPrivate();
    imp->codecpar = avcodec_parameters_alloc();
}

ZAVStream::~ZAVStream() {
    if (imp != nullptr && imp->codecpar != nullptr) {
        avcodec_parameters_free(&imp->codecpar);
        imp->codecpar = nullptr;
    }
    if (imp != nullptr) {
        delete imp;
        imp = nullptr;
    }
}