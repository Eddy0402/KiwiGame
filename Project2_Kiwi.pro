#-------------------------------------------------
#
# Project created by QtCreator 2014-06-09T15:48:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2_Kiwi
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
	render/model/mesh.cpp \
    render/model/model.cpp \
    render/model/texture.cpp \
    render/model/resourcemanager.cpp \
    render/rendererbase.cpp

HEADERS += window.h \
	render/model/mesh.h \
    render/model/model.h \
    render/model/texture.h \
    render/model/resourcemanager.h \
    render/rendererbase.h

CONFIG += c++11
INCLUDEPATH += /opt/Qt5.3.0/5.3/gcc_64/include/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib64/release/ -lloki
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib64/debug/ -lloki
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib64/ -lloki

INCLUDEPATH += $$PWD/../../../../../../usr/lib64
DEPENDPATH += $$PWD/../../../../../../usr/lib64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/release/ -lassimp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/lib/debug/ -lassimp
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lassimp

INCLUDEPATH += $$PWD/../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../usr/local/include

OTHER_FILES += \
    shaders/test.vert \
    shaders/test.frag
