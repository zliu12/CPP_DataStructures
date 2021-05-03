cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 14)
project(4 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(4 main.cpp
               Color.cpp Color.h
               Cursor.cpp Cursor.h
               Data.cpp Data.h
               DropDown.cpp DropDown.h
               EventHandler.cpp EventHandler.h
               Fonts.cpp Fonts.h
               GUIComponents.cpp GUIComponents.h
               History.cpp History.h
               Input.cpp Input.h
               InputBox.cpp InputBox.h
               Item.cpp Item.h
               Itemlist.cpp Itemlist.h
               Iterator.cpp Iterator.h 
               KeyBoard.cpp KeyBoard.h 
               LinkedList.cpp LinkedList.h 
               MouseEvent.h 
               MyClass.cpp MyClass.h 
               Node.cpp Node.h 
               ObjectState.cpp ObjectState.h 
               SnapShot.cpp SnapShot.h 
               Stacks.cpp Stacks.h 
               State.cpp State.h 
               Title.cpp Title.h 
               Typing.cpp Typing.h 
               Word.cpp Word.h)

target_link_libraries(4 sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
