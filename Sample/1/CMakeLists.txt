set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 3.0.0)
project(1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(1 main.cpp
               Cursor.cpp Cursor.hpp
               EventHandler.hpp
               GUIComponent.hpp
               History.cpp History.hpp
               KeyShortcuts.cpp KeyShortcuts.hpp
               linked_list.h
               list.h
               MouseEvents.cpp MouseEvents.hpp
               Snapshot.cpp Snapshot.hpp
               SnapshotInterface.hpp
               stack.h
               States.cpp States.hpp
               TextField.cpp TextField.hpp
               TextInput.cpp TextInput.hpp
               TextInputBox.cpp TextInputBox.hpp
               Typing.cpp Typing.hpp
               Word.cpp Word.hpp)

target_link_libraries(sample1 sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
