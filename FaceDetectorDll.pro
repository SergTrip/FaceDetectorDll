#-------------------------------------------------
#
# Project created by QtCreator 2015-05-31T23:48:28
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = FaceDetectorDll
TEMPLATE = lib

DEFINES += FACEDETECTORDLL_LIBRARY

SOURCES += facedetectordll.cpp

HEADERS += facedetectordll.h\
        facedetectordll_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
