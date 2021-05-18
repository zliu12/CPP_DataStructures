cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME project1)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp EventHandler.cpp EventHandler.h main.cpp States.cpp States.h Snapshot.cpp Snapshot.h GUIComponent.cpp GUIComponent.h KeyboardShortcut.cpp KeyboardShortcut.h MouseEvent.cpp MouseEvent.h History.cpp History.h TextInput.cpp TextInput.h Typing.cpp Typing.h SnapshotInterface.cpp SnapshotInterface.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h Node.h State.cpp State.h Label.cpp Label.h Textbox.cpp Textbox.h ChangeColor.cpp ChangeColor.h Cursor.cpp Cursor.h Node_iterator.h Node_iterator.cpp LinkedList.cpp LinkedList.h MultiText.cpp MultiText.h Item.cpp Item.h ItemList.cpp ItemList.h InputBox.cpp InputBox.h DropDownMenu.cpp DropDownMenu.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/Users/xu200/Downloads/Applications/SFML/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
if (POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()