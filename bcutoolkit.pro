QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    digitalclock.cpp \
    machinesoverview.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp

HEADERS += \
    digitalclock.h \
    machinesoverview.h \
    mainpage.h \
    mainwindow.h

FORMS += \
    machinesoverview.ui \
    mainpage.ui \
    mainwindow.ui

TRANSLATIONS += \
    bcutoolkit_es_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    gres/search-512.png

RESOURCES += \
    icons.qrc
