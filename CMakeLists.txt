cmake_minimum_required(VERSION 3.10)
project(myffmpeg)
#aux_source_directory(. HOME_PATH)
add_definitions("-Wall -std=c++11")
#set(CMAKE_CXX_STANDARD 14)
set(BUILD_DIR ${PROJECT_BINARY_DIR}/../${PROJECT_NAME}-build)
set(CME_LIBRARY_OUTPUT_DIRECTORY "${LIBDIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)

include_directories(/usr/local/ffmpeg/include)#ffmpeg 依赖的头文件路径
link_directories(/usr/local/ffmpeg/lib) #ffmpeg 依赖的库文件路径
add_subdirectory(avcore)
add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} avcore libavcodec.so libavformat.so libavfilter.so libavutil.so libavdevice.so libswscale.so)

