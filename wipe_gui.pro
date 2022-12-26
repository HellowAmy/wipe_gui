QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += -pthread

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
    lib/inter_wipe.cpp \
    lib/wipe/arcfour.c \
    lib/wipe/md5.c \
    lib/wipe/misc.c \
    lib/wipe/random.c \
    lib/wipe/wipe.c \
    main.cpp \
    qt_move_it.cpp \
    wid_main.cpp \
    wid_prog_show.cpp \
    wid_show_info.cpp \
    widget.cpp

HEADERS += \
    lib/inter_wipe.h \
    lib/wipe/arcfour.h \
    lib/wipe/md5.h \
    lib/wipe/misc.h \
    lib/wipe/random.h \
    lib/wipe/version.h \
    lib/wipe/wipe.h \
    qt_move_it.h \
    wid_main.h \
    wid_prog_show.h \
    wid_show_info.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    lib/wipe/BUGS \
    lib/wipe/CHANGES \
    lib/wipe/GPL \
    lib/wipe/README \
    lib/wipe/examples/wipefd0 \
    lib/wipe/examples/wswap.pl \
    lib/wipe/randompipe.sh \
    lib/wipe/trtur \
    lib/wipe/wipe \
    lib/wipe/wipe.1 \
    lib/wipe/wipe.tr-asc.1 \
    lib/wipe/wipe.tr.1
