#-------------------------------------------------
#
# Project created by QtCreator 2011-11-08T08:02:37
#
#-------------------------------------------------

LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_calib3d490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_core490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_dnn490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_features2d490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_flann490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_gapi490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_highgui490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_imgcodecs490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_imgproc490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_ml490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_objdetect490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_photo490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_stitching490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_video490.dll
LIBS += D:\utilidades\softwares\opencv\build\install\x64\mingw\bin\libopencv_videoio490.dll

INCLUDEPATH += D:\utilidades\softwares\opencv\build\include
DEPENDPATH += D:\utilidades\softwares\opencv\build\include

QT       += core gui svg printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = circuito
TEMPLATE = app

contains(QT_CONFIG, opengl):QT += opengl

SOURCES += main.cpp\
        mainwindow.cpp \
    circuititem.cpp \
    view.cpp \
    circuitscene.cpp \
    circuitviewer.cpp \
    conector.cpp

HEADERS  += mainwindow.h \
    circuititem.h \
    view.h \
    circuitscene.h \
    circuitviewer.h \
    conector.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc







































