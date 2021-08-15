project(ZMedia)

include_directories(../)

add_executable(${PROJECT_NAME} ZPlayer.cpp)

target_link_libraries(ZMedia ZThread)