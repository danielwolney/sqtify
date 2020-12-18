include(gtest_dependency.pri)

QT       += core testlib gui network networkauth sql multimedia svg

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

DEFINES += TESTS

include(src.pri)

SOURCES += \
    tst/main.cpp
