//
// Created by Zippo on 2021/8/15.
//

#include "ZThread.h"
#include <thread>

int ZThread::start() {
    std::thread t(&ZThread::run, this);
    t.detach();
    return EXIT_SUCCESS;
}