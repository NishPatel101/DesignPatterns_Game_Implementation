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
	Graphics/src/textGui.cpp
	GameBoard/gameBoard.cpp
	PlayerController/playerController.cpp
	BattleVisitor/BattleVisitor.cpp
	Character/Character.cpp
	FileRead/fileReader.cpp
	Equipment/src/Axe.cpp
	Equipment/src/Deadly.cpp
	Equipment/src/EquipmentDecorator.cpp
	Equipment/src/Flimsy.cpp
	Equipment/src/Mighty.cpp
	Equipment/src/Sword.cpp
)

ADD_EXECUTABLE(runUnitTest
    Character/Character.cpp
    Equipment/src/Axe.cpp
    Equipment/src/Deadly.cpp
    Equipment/src/EquipmentDecorator.cpp
    Equipment/src/Flimsy.cpp
    Equipment/src/Mighty.cpp
    Equipment/src/Sword.cpp
    test/unit_test.cpp
)
target_link_libraries(gameAsciiRpg ${CURSES_LIBRARIES})
TARGET_LINK_LIBRARIES(runUnitTest gtest)
TARGET_COMPILE_DEFINITIONS(runUnitTest PRIVATE gtest_disable_pthreads=ON)
