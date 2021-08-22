cmake_minimum_required(VERSION 3.20)

include_directories(../3rdpart/ffmpeg/include)

add_library(ZAV ZAVReader.cpp ZAVPacket.cpp ZAVStream.cpp ZAVDecoder.cpp)