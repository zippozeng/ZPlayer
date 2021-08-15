//
// Created by Zippo on 2021/8/15.
//
#include "ZAV.h"
#include "ZAVPacketPrivate.h"

ZAVPacket::ZAVPacket() {
    imp = new ZAVPacketPrivate();
    imp->pkt = av_packet_alloc();
}

ZAVPacket::~ZAVPacket() {
    if (imp->pkt != nullptr) {
        av_packet_free(&imp->pkt);
        imp->pkt = nullptr;
    }
    if (imp != nullptr) {
        delete imp;
        imp = nullptr;
    }
}