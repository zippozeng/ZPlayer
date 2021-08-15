project(ZMedia)

include_directories(../)
link_directories(../3rdpart/ffmpeg/lib)

add_executable(${PROJECT_NAME} ZPlayer.cpp)

target_link_libraries(ZMedia ZThread ZAV)

target_link_libraries(ZMedia avcodec)
target_link_libraries(ZMedia avdevice)
target_link_libraries(ZMedia avformat)
target_link_libraries(ZMedia avutil)
target_link_libraries(ZMedia swresample)
target_link_libraries(ZMedia swscale)