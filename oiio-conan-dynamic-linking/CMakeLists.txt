cmake_minimum_required(VERSION 3.15)
project(oiio-linking-demo CXX)

find_package(OpenImageIO REQUIRED)
find_package(fmt REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenImageIO::OpenImageIO
                                              OpenImageIO::OpenImageIO_Util
                                              fmt::fmt)
