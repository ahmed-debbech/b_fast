QT       += core gui
QT       += core sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    diagoptions.cpp \
    dialog.cpp \
    dialog2.cpp \
    main.cpp \
    mainwindow.cpp \
    res.cpp

HEADERS += \
    client.h \
    diagoptions.h \
    dialog.h \
    dialog2.h \
    mainwindow.h \
    res.h

FORMS += \
    diagoptions.ui \
    dialog.ui \
    dialog2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_SONS=icon.ico
DISTFILES += \
    icon.ico

RESOURCES += \
    icon1.qrc
