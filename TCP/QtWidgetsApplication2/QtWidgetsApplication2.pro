﻿# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------
QT       += core gui network
TEMPLATE = app
TARGET = QtWidgetsApplication2
DESTDIR = ../x64/Debug
CONFIG += debug
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
HEADERS += ./Server.h \
    ./Client.h
SOURCES += ./Client.cpp \
    ./Server.cpp \
    ./main.cpp
FORMS += ./Client.ui \
    ./Server.ui
RESOURCES += Server.qrc
