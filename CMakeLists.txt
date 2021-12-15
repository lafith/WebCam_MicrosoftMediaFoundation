cmake_minimum_required(VERSION 3.0.0)
project(WebCam_MicrosoftMediaFoundation VERSION 0.1.0)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

#add_executable(OpenCV_Test main.cpp)
add_executable(main
                ${SOURCES})

#target_link_libraries( OpenCV_Test ${OpenCV_LIBS} )
target_link_libraries( main ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
