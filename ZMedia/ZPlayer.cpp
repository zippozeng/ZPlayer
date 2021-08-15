//
// Created by Zippo on 2021/8/15.
//

#include <iostream>
#include "ZAV/ZAV.h"

int main() {
    ZAVReader reader;
    int ret = reader.open("../assets/demo.mp4");
    if (ret) {
        std::cout << "open file failure!" << std::endl;
        return -1;
    }
    while (true) {
        ZAVPacket pkt;
        ret = reader.read(&pkt);
        if (ret) {
            break;
        }
        std::cout << "read packet success!" << std::endl;
    }
    reader.close();
    std::cout << "read ret:" << ret << std::endl;
    return 0;
}