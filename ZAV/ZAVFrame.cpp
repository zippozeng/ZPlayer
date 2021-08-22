//
// Created by Zippo on 2021/8/22.
//

#include "ZAV.h"
#include "ZAVFramePrivate.h"

ZAVFrame::ZAVFrame() {
    imp->frame = av_frame_alloc();
}

ZAVFrame::~ZAVFrame() {
    if (imp != nullptr && imp->frame != nullptr) {
        av_frame_free(&imp->frame);
        imp->frame = nullptr;
    }
    if (imp != nullptr) {
        delete imp;
        imp = nullptr;
    }
}