CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(gameAsciiRpg
	asciiRpg.cpp
        Graphics/src/graphics.cpp
        Graphics/src/windowGui.cpp
        Graphics/src/worldGui.cpp
        Graphics/src/actionGui.cpp
	Graphics/src/imagesGui.cpp
	fileReader.cpp

)

ADD_EXECUTABLE(runUnitTest
    test/unit_test.cpp
)
target_link_libraries(gameAsciiRpg ${CURSES_LIBRARIES})
TARGET_LINK_LIBRARIES(runUnitTest gtest)
TARGET_COMPILE_DEFINITIONS(runUnitTest PRIVATE gtest_disable_pthreads=ON)
