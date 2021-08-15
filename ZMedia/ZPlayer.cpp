//
// Created by Zippo on 2021/8/15.
//

#include <iostream>
#include <thread>
#include "ZThread/ZThread.h"

class MyThread : public ZThread {
private:
    int a = 0;
public:

    explicit MyThread(int _a) {
        a = _a;
    }

    void run() override {
        printf("MyThread %d\n", a);
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyThread t(10);
    t.start();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}