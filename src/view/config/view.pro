QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../controller/controller.cc \
    ../../main.cc \
    ../../model/facade/facade.cc \
    ../../model/maze_builder/maze_builder.cc \
    ../../model/maze_reader/maze_reader.cc \
    ../../model/maze_write/maze_write.cc \
    ../../model/way/Way.cc \
    ../mainwindow/mainwindow.cc \
    ../scene/scene.cc

HEADERS += \
    ../../controller/controller.h \
    ../../model/facade/facade.h \
    ../../model/maze_builder/maze_builder.h \
    ../../model/maze_reader/maze_reader.h \
    ../../model/maze/maze.h \
    ../../model/maze_write/maze_write.h \
    ../../model/way/Way.h \
    ../mainwindow/mainwindow.h \
    ../scene/scene.h

FORMS += \
    ../form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
