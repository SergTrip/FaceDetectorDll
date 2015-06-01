#-------------------------------------------------
#
# Project created by QtCreator 2015-05-31T23:48:28
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET      = FaceDetectorDll

TEMPLATE    = lib

DEFINES += FACEDETECTORDLL_LIBRARY

SOURCES +=  \
#            facedetectordll.cpp         \
            facerecognizer.cpp

HEADERS +=  \
#            facedetectordll.h           \
            facedetectordll_global.h    \
            facerecognizer.h

unix {
    target.path = /usr/lib
    INSTALLS += target

    CONFIG (  release, debug | release    ) {
        TARGET      = FaceDetectorDll
    }

    CONFIG ( debug, debug | release    ) {
        TARGET      = FaceDetectorDlld
    }
}
