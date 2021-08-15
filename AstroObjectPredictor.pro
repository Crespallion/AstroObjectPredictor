#-------------------------------------------------
#
# Project created by QtCreator 2019-10-26T16:39:57
#
#-------------------------------------------------


QT += core gui
QT += webkit
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AstroObjectPredictor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plwindow.cpp

INCLUDEPATH += /root/Projects/Project/geolite2PP/src-lib

HEADERS  += mainwindow.h \
    helpfunctions.h \
    plwindow.h

FORMS    += mainwindow.ui \
    plwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../geolite2PP/src-lib/release/ -lgeolite2++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../geolite2PP/src-lib/debug/ -lgeolite2++
else:unix: LIBS += -L$$PWD/../../geolite2PP/src-lib/ -lgeolite2++

INCLUDEPATH += $$PWD/../../geolite2PP/src-lib
DEPENDPATH += $$PWD/../../geolite2PP/src-lib

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../geolite2PP/src-lib/release/geolite2++.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../geolite2PP/src-lib/debug/geolite2++.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../geolite2PP/src-lib/libgeolite2++.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Project/libmaxminddb-1.3.2/src/.libs/release/ -lmaxminddb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Project/libmaxminddb-1.3.2/src/.libs/debug/ -lmaxminddb
else:unix: LIBS += -L$$PWD/../../Project/libmaxminddb-1.3.2/src/.libs/ -lmaxminddb

INCLUDEPATH += $$PWD/../../Project/libmaxminddb-1.3.2/src/.libs
DEPENDPATH += $$PWD/../../Project/libmaxminddb-1.3.2/src/.libs

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Project/libmaxminddb-1.3.2/src/.libs/release/maxminddb.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Project/libmaxminddb-1.3.2/src/.libs/debug/maxminddb.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../Project/libmaxminddb-1.3.2/src/.libs/libmaxminddb.a
