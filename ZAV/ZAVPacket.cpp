//
// Created by Zippo on 2021/8/15.
//
#include "ZAV.h"

ZAVPacket::ZAVPacket() {
    pkt = av_packet_alloc();
}

ZAVPacket::~ZAVPacket() {
    if (pkt != nullptr) {
        av_packet_free(&pkt);
        pkt = nullptr;
    }
}