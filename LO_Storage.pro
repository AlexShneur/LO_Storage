QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "include"
LIBS += -L"libs" -llibpq    #находящуюся внутри проекта папку libs с библиотеками PostgreSQL необходимо скопировать туда, где собирается проект.
                            #сохраняемые параметры подключения к БД лежат в файле configParams.txt, который находится рядом с папкой debug

SOURCES += \
    dialogpullfile.cpp \
    dialogpushfile.cpp \
    main.cpp \
    mainwindow.cpp \
    pgconnection.cpp \
    pgoperations.cpp

HEADERS += \
    dialogpullfile.h \
    dialogpushfile.h \
    mainwindow.h \
    pgconnection.h \
    pgoperations.h

FORMS += \
    dialogpullfile.ui \
    dialogpushfile.ui \
    mainwindow.ui

TRANSLATIONS += \
    LO_Storage_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
