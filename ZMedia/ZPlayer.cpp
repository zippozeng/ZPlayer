//
// Created by Zippo on 2021/8/15.
//

#include <iostream>
#include <vector>
#include "ZAV/ZAV.h"

int main() {
    ZAVReader reader;
    int ret = reader.open("/Users/zippo/Code/CLionProjects/ZPlayer/assets/demo.mp4");
    if (ret) {
        std::cout << "open file failure!" << std::endl;
        return -1;
    }
    std::vector<ZAVDecoder *> decoders;

    int streamCount = reader.getStreamCount();
    for (int i = 0; i < streamCount; ++i) {
        ZAVStream stream;
        reader.getStream(&stream, i);
        printf("streamIndex:%d\n", stream.index);

        auto *decoder = new ZAVDecoder();
        ret = decoder->init(&stream);
        if (ret) {
            printf("init decoder fail\n");
        }
        decoders.push_back(decoder);
    }

    while (true) {
        ZAVPacket pkt;
        ret = reader.read(&pkt);
        if (ret) {
            break;
        }
        int streamIndex = pkt.getStreamIndex();
        ZAVDecoder *decoder = decoders[streamIndex];
        ret = decoder->sendPacket(pkt);
        if (ret) {
            continue;
        }
        while (true) {
            ZAVFrame frame;
            ret = decoder->receiveFrame(&frame);
            if (ret) {
                break;
            }
        }
//        std::cout << "read packet success!" << std::endl;
    }

    // free
    reader.close();
    for (int i = 0; i < decoders.size(); ++i) {
        ZAVDecoder *decoder = decoders[i];
        decoder->close();
        delete decoder;
    }
    decoders.clear();
    return 0;
}
