//
// Created by Zippo on 2021/8/15.
//

#ifndef ZPLAYER_ZTHREAD_H
#define ZPLAYER_ZTHREAD_H

class ZThread {
public:
    virtual void run() = 0;

    int start();

};


#endif //ZPLAYER_ZTHREAD_H
