cmake_minimum_required(VERSION 3.5)

project(coursachTry VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        nextwindowsecond.cpp
        nextwindowsecond.h
        nextwindowsecond.ui

        nextwindowthird.cpp
        nextwindowthird.h
        nextwindowthird.ui

        nextwindowfourth.cpp
        nextwindowfourth.h
        nextwindowfourth.ui

        nextwindowfifth.cpp
        nextwindowfifth.h
        nextwindowfifth.ui

        nextwindowsixth.cpp
        nextwindowsixth.h
        nextwindowsixth.ui

        paragraph.h
        paragraph.cpp

        alhoritm.cpp
        alhoritm.h

        financenote.cpp
        financenote.h

        header.h

        node.cpp
        node.h

        nodenotfoundexception.h

        note.h
        note.cpp

        phoneBook.cpp
        phoneBook.h

        task.cpp
        task.h

        Tree.cpp
        Tree.h

        wishNote.cpp
        wishNote.h

        exception.h
        exceptioninterface.h
        exceptions.h
        fileexception.h
        fileincorrectmodeexception.h
        filenotfoundexception.h
        filenotopenexception.h
        filestream.h

        header2.h

        treeiterator.cpp
        treeiterator.h

        alhoritmexception.h

        stack.h
        stack.cpp

        massive.cpp
        massive.h

        languageexception.h

        inputexception.h

        formatexception.h

        arrayboundsexception.h

        nullvalueexception.h

        filenotexistexception.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(coursachTry
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET coursachTry APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(coursachTry SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(coursachTry
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(coursachTry PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(coursachTry PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS coursachTry
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(coursachTry)
endif()
