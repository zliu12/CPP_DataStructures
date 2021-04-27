cmake_minimum_required(VERSION 3.17)
project(ProjectOneTextBox)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectOneTextBox main.cpp Box.cpp Box.h Label.cpp Label.h TextInput.cpp TextInput.h
        State.cpp State.h States.cpp States.h Typer.cpp Typer.h Cursor.cpp Cursor.h GUIComponents.cpp GUIComponents.h KeyBoardShortCut.cpp KeyBoardShortCut.h EventHandler.cpp EventHandler.h SnapshotInterface.cpp SnapshotInterface.h Snapshot.cpp Snapshot.h History.cpp History.h KeyBoardEvent.cpp KeyBoardEvent.h LinkedList.cpp LinkedList.h Node.h MouseEvents.cpp MouseEvents.h)
target_link_libraries(ProjectOneTextBox sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)